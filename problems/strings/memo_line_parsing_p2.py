"""
MEMO-LINE PARSING Pt. 2
FROM: Stripe
DIFFICULTY: Easy/Medium
LANGUAGE: Python

Refer to memo_line_parsing_p1.py for details on the OG problem.

In addition to memo-line matching, we want to support amount-based matching.
You'll be given almost identical input to part1, but the memo-line will either
be the format used in part1 or an arbitrary description of the payment. For
instance:
```
paymentUUID,500,Bank transfer
```

You'll match these payments to invoices with the amount due equal to the
incoming payment amount. If there are multiple invoices, choose the one with
the earliest due date.

For instance:
```
reconcile_payment("paymentUUID,500,Bank transfer", [
                    "invoiceA,2024-02-01,500",
                    "invoiceB,2024-01-01,500"
                ])
```
Should return
```
paymentUUID pays off 500 for invoiceB due on 2024-01-01
```
"""

import re
from typing import List

DATE_FORMAT = re.compile(r"\d{4}-\d{2}-\d{2}")
MEMO_LINE_FORMAT = re.compile(r"Paying off: (.+)")


def parse_payment(payment_str: str) -> tuple[str, int, str]:
    payment_id, amount, memo_line = payment_str.split(",", maxsplit=2)
    m = MEMO_LINE_FORMAT.match(memo_line)
    if not m:
        invoice = ""
    else:
        invoice = m.group(1)

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


def amount_match_payment(payment_amount: int, parsed_invoices):
    earliest_date = None
    earliest_invoice = None
    for invoice_id, (date, invoice_amount) in parsed_invoices.items():
        if invoice_amount == payment_amount and (
            earliest_date is None or date < earliest_date
        ):
            earliest_date = date
            earliest_invoice = invoice_id

    return (
        (earliest_invoice, earliest_date, payment_amount)
        if earliest_invoice is not None
        else earliest_invoice
    )


def memo_match_payment(invoice_id, payment_id, payment_amount, parsed_invoices):
    matched_invoice = parsed_invoices.get(invoice_id, None)

    if matched_invoice is None:
        raise ValueError(f"{payment_id} pays off no invoices")

    date, invoice_amount = matched_invoice
    paid_amount = min(invoice_amount, payment_amount)

    return date, paid_amount


def reconcile_payment(payment: str, invoices: List[str]) -> str:
    try:
        payment_id, payment_amount, invoice_id = parse_payment(payment)
    except (ValueError, TypeError) as e:
        return f"Failed to parse payment: {e}"
    try:
        parsed_invoices = parse_invoices(invoices)
    except (ValueError, AttributeError, TypeError) as e:
        return f"Failed to parse invoices: {e}"

    if invoice_id == "":
        try:
            matched_invoice_id, date, paid_amount = amount_match_payment(
                payment_amount, parsed_invoices
            )
        except TypeError as e:
            return str(e)
    else:
        try:
            date, paid_amount = memo_match_payment(
                invoice_id, payment_id, payment_amount, parsed_invoices
            )
            matched_invoice_id = invoice_id
        except ValueError as e:
            return str(e)

    return format_return_string(payment_id, matched_invoice_id, date, paid_amount)


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

    # Amount-based matching test case from description
    payment2 = "paymentUUID,500,Bank transfer"
    invoices2 = [
        "invoiceA,2024-02-01,500",
        "invoiceB,2024-01-01,500",
    ]
    expected_res2 = "paymentUUID pays off 500 for invoiceB due on 2024-01-01"
    print(f"Expected: {expected_res2} | \
            Got: {reconcile_payment(payment2, invoices2)}")
