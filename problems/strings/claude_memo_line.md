❯ One concern is that if there are lots of invoices, iterating
  over the dictionary to find matches for amount_based_matching is
  expensive. What are ways I could discuss working around this in
  an interview

  Thought for 3s (ctrl+o to expand)

⏺ A few approaches you could discuss:

  1. Index by amount (hash map)
  Pre-build a dict[int, list[tuple[date, invoice_id]]] mapping
  amount → list of invoices. Lookup becomes O(1) per payment
  instead of O(n). If you keep each list sorted by date, finding
  the earliest is O(1) too.

  2. Index by amount with a heap/sorted structure
  Same idea but use a min-heap keyed on date per amount bucket.
  Good if invoices are streaming in and you can't pre-sort.

  3. Sort once, binary search
  If you process many payments against the same invoice set, sort
  invoices by (amount, date) once. Then binary search for the
  amount and take the first hit (earliest date). O(n log n) setup,
  O(log n) per query.

  Interview framing:

  - Clarify the access pattern — "Are we calling this once or for
  many payments against the same invoices?" If many payments,
  amortizing a preprocessing step (index/sort) is clearly worth it.
  - Space vs. time tradeoff — The index costs O(n) extra space but
  drops per-query time from O(n) to O(1).
  - Follow-up: what if amounts aren't exact? — If they ask about
  fuzzy/range matching, a sorted list with binary search
  generalizes better than a hash map.

  The strongest interview answer is: "I'd pre-process the invoices
  into a dict[amount] → earliest_invoice (or sorted list if there
  are ties to break later), since the current O(n) scan per payment
  becomes a bottleneck at scale."

✻ Cogitated for 13s

❯ If this were an interview scenario, what other issues/probing
  questions might you raise and how would I best answer

  Thought for 2s (ctrl+o to expand)

⏺ Here are likely interviewer follow-ups and strong answers:

  "What if a payment partially pays an invoice?"
  - You already handle this with min(invoice_amount,
  payment_amount) in the memo path. Discuss: do you need to track
  remaining balance? Should parse_invoices return mutable state so
  you can decrement? Mention that in a real system you'd persist
  the remaining balance and match future payments against it.

  "What if multiple payments arrive for the same invoice?"

⏺ Here are likely interviewer follow-ups and strong answers:

  "What if a payment partially pays an invoice?"
  - You already handle this with min(invoice_amount, payment_amount) in the memo path. Discuss:
  do you need to track remaining balance? Should parse_invoices return mutable state so you can
  decrement? Mention that in a real system you'd persist the remaining balance and match future
  payments against it.

  "What if multiple payments arrive for the same invoice?"
  - The current code is stateless — it doesn't track prior payments. Talk about introducing a
  reconciliation ledger (running balance per invoice). Mention idempotency: what if the same
  payment is processed twice?

  "What if both memo-line and amount match, but to different invoices?"
  - State your priority rule clearly: "Memo-line is an explicit reference, so it wins. Amount
  matching is a fallback heuristic." Interviewers want to hear you define behavior at ambiguous
  boundaries.

  "How would you handle malformed input at scale?"
  - Discuss fail-open vs. fail-closed. In payments, you likely want to flag for manual review
  rather than silently dropping. Mention logging/alerting on parse failures, dead-letter queues
  for unmatched payments.

  "What about concurrency — two payments arriving simultaneously for the same invoice?"
  - Talk about locking or optimistic concurrency (version on the invoice row, CAS). Mention that
  double-paying an invoice is a real-world concern and you'd want atomicity on the
  match-and-debit step.

  "How would you test this?"
  - Edge cases: zero-amount payments, invoices with identical dates and amounts, empty invoice
  list, memo-line referencing a nonexistent invoice, extremely large input sets. Mention
  property-based testing (every payment either matches exactly one invoice or returns a clear "no
  match").

  "Why not use a database query instead of in-memory matching?"
  - At scale, this is a SELECT ... WHERE amount = ? ORDER BY due_date LIMIT 1 with an index on
  (amount, due_date). Shows you understand that interview code is a simplification of what would
  be a DB-backed system in production. Mention indexing strategy directly ties back to the data
  structure discussion.

  General advice for delivering these:
  - Lead with the tradeoff, not the solution. ("The tension here is X vs. Y — I'd lean toward Y
  because...")
  - Ask clarifying questions before answering. ("Is this a batch process or real-time? That
  changes whether I'd pre-index.")
  - Acknowledge the scope boundary. ("In this interview context I'd keep it simple, but in
  production I'd want...")
