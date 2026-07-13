"""
MEMO-LINE PARSING
FROM: Stripe
DIFFICULTY: Easy/Medium
LANGUAGE: Python

Stripe's invoice product allows businesses to create and send invoices to their
customers. Whilst many invoices can be paid direclty, there are cases where
standalone payments need to be reconciled with open invoices for a customer.

Your task is to write a program that matches incoming payments to their
corresponding invoices based on the payment's memo line. An example input
string for a payment looks like this:

payment="paymentABC,1000,Paying off: invoiceC", \
        invoices=["invoiceA,2024-01-01", "invoiceB,2024-02-01,200" \
        "invoiceC,2023-01-30,1000"]

(Payment format) Each comma-separated element represents a different piece of \
information about the payment:
1. The payment ID (e.g. payment123)
2. The payment amount (in USD minor units e.g. $1.00 = 100)
3. The memo line, which always follows the format "Paying off: {INVOICE}"

(Invoices format) Each comma-separated element represents a different piece \
of information about the payment:
1. The invoice ID
2. The due-date for that invoice
3. The amount due on the invoice (in USD minor units e.g. $1.00 = 100)

Example:
reconcile_payment(payment, invoices) should return:
```
paymentABC pays off 1000 for invoiceC due on 2023-01-30
```
"""

import re
from typing import List

DATE_FORMAT = re.compile(r'\d{4}-\d{2}-\d{2}')


def parse_payment(payment_str:str) -> tuple[str, int, str]:
    payment_id, amount, memo_line = payment_str.split(",", maxsplit=2)
    _, invoice = memo_line.split(":")

    return payment_id, int(amount), invoice.strip()

def parse_invoices(invoices_list: List[str]):
    invoices_dict = {}
    for invoice in invoices_list:
        invoice_id, date, amount = invoice.split(",", maxsplit=2)
        m = DATE_FORMAT.match(date)
        if not m:
            raise AttributeError("Invalid date format")
        invoices_dict[invoice_id] = (date, int(amount))
    return invoices_dict

def format_return_string(pay_id, invoice_id, date_ref, amount) -> str:
    return f"{pay_id} pays off {amount} for {invoice_id} due on {date_ref}"

def reconcile_payment(payment:str, invoices:List[str]) -> str:
    try:
        payment_id, payment_amount, invoice_id = parse_payment(payment)
    except (ValueError, TypeError) as e:
        return f"Failed to parse payment: {e}"
    try:
        parsed_invoices = parse_invoices(invoices)
    except (ValueError, AttributeError, TypeError) as e:
        return f"Failed to parse invoices: {e}"

    matched_invoice = parsed_invoices.get(invoice_id, None)

    if matched_invoice is None:
        return f"{payment_id} pays off no invoices"

    date, invoice_amount = matched_invoice
    paid_amount = min(invoice_amount, payment_amount)

    return format_return_string(payment_id, invoice_id, date, paid_amount)


if __name__ == "__main__":
    payment = "payment5,1000,Paying off: invoiceC"
    invoices = [
        "invoiceA,2024-01-01,100",
        "invoiceB,2024-02-01,200",
        "invoiceC,2023-01-30,1000",
    ]
    expected_res = "payment5 pays off 1000 for invoiceC due on 2023-01-30"
    print(f"Expected: {expected_res} | \
            Got: {reconcile_payment(payment, invoices)}")
