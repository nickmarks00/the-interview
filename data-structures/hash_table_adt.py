""" Hash Table ADT

Defines a Hash Table using Linear Probing for conflict resolution.
It currently rehashes the primary cluster to handle deletion.
"""

__author__ = "Brendon Taylor"
__docformat__ = "reStructuredText"
__modified__ = "16/05/2020"
__since__ = "14/05/2020"

import unittest
from typing import Generic, TypeVar

from referential_array import ArrayR

T = TypeVar("T")


class LinearProbeTable(Generic[T]):
    """
    Linear Probe Hash Table

    constants:
        MIN_CAPACITY: smallest valid table size
        DEFAULT_TABLE_SIZE: default table size used in the __init__
        DEFAULT_HASH_TABLE: default hash base used for the hash function
        PRIMES: list of prime numbers to use for resizing

    attributes:
        count: number of elements in the hash table
        array: used to represent our internal array
        table_size: current size of the hash table
    """

    PRIMES = [
        3,
        7,
        11,
        17,
        23,
        29,
        37,
        47,
        59,
        71,
        89,
        107,
        131,
        163,
        197,
        239,
        293,
        353,
        431,
        521,
        631,
        761,
        919,
        1103,
        1327,
        1597,
        1931,
        2333,
        2801,
        3371,
        4049,
        4861,
        5839,
        7013,
        8419,
        10103,
        12143,
        14591,
        17519,
        21023,
        25229,
        30313,
        36353,
        43627,
        52361,
        62851,
        75521,
        90523,
        108631,
        130363,
        156437,
        187751,
        225307,
        270371,
        324449,
        389357,
        467237,
        560689,
        672827,
        807403,
        968897,
        1162687,
        1395263,
        1674319,
        2009191,
        2411033,
        2893249,
        3471899,
        4166287,
        4999559,
        5999471,
        7199369,
    ]

    MIN_CAPACITY = 1

    DEFAULT_TABLE_SIZE = 17
    DEFAULT_HASH_BASE = 31

    def __init__(self, table_size: int = DEFAULT_TABLE_SIZE) -> None:
        """
        :complexity: O(N) where N is the table_size
        """
        self.count = 0
        self.table = ArrayR(max(self.MIN_CAPACITY, table_size))
        self.next_prime = 0

        while LinearProbeTable.PRIMES[self.next_prime] <= table_size:
            self.next_prime += 1

    def __len__(self) -> int:
        """
        Returns number of elements in the hash table
        :complexity: O(1)
        """
        return self.count

    def __delitem__(self, key: str) -> None:
        """
        Deletes an item from our hash table by rehashing the
        remaining items in the current primary cluster
        :raises KeyError: when the key doesn't exist
        :complexity best: O(K) finds the position straight away and doesn't have to rehash
                          where K is the size of the key
        :complexity worst: O(K + N) when it has to rehash all items in the hash table
                          where N is the table size
        """
        position = self.__linear_probe(key, False)
        self.table[position] = None
        self.count -= 1

        position = (position + 1) % len(self.table)
        while self.table[position] is not None:
            item = self.table[position]
            self.table[position] = None
            self.count -= 1
            self[str(item[0])] = item[1]
            position = (position + 1) % len(self.table)

    def __rehash(self) -> None:
        """
        Need to resize table and reinsert all values
        :complexity:
        """
        new_hash = LinearProbeTable(LinearProbeTable.PRIMES[self.next_prime])
        self.next_prime += 1

        for i in range(len(self.table)):
            if self.table[i] is not None:
                new_hash[str(self.table[i][0])] = self.table[i][1]

        self.count = new_hash.count
        self.table = new_hash.table

    def __linear_probe(self, key: str, is_insert: bool) -> int:
        """
        Find the correct position for this key in the hash table using linear probing
        :complexity best: O(K) first position is empty
                          where K is the size of the key
        :complexity worst: O(K + N) when we've searched the entire table
                           where N is the table_size
        :raises KeyError: When a position can't be found
        """
        position = self.hash(key)  # get the position using hash

        if is_insert and self.is_full():
            raise KeyError(key)

        for _ in range(len(self.table)):  # start traversing
            if self.table[position] is None:  # found empty slot
                if is_insert:
                    return position
                raise KeyError(key)  # so the key is not in
            elif self.table[position][0] == key:  # found key
                return position
            else:  # there is something but not the key, try next
                position = (position + 1) % len(self.table)

    def __getitem__(self, key: str) -> T:
        """
        Get the item at a certain key
        :see: #self.__linear_probe(key: str, is_insert: bool)
        :raises KeyError: when the item doesn't exist
        """
        position = self.__linear_probe(key, False)
        return self.table[position][1]

    def __setitem__(self, key: str, data: T) -> None:
        """
        Set an (key, data) pair in our hash table
        :see: #self.__linear_probe(key: str, is_insert: bool)
        :see: #self.__rehash()
        """
        try:
            position = self.__linear_probe(key, True)
        except KeyError:
            self.__rehash()
            self.__setitem__(key, data)  # try again
        else:
            if self.table[position] is None:
                self.count += 1
            self.table[position] = (key, data)

    def is_empty(self):
        """
        Returns whether the hash table is empty
        :complexity: O(1)
        """
        return self.count == 0

    def is_full(self):
        """
        Returns whether the hash table is full
        :complexity: O(1)
        """
        return self.count == len(self.table)

    def hash(self, key: str) -> int:
        """
        Universal Hash function
        :post: returns a valid position (0 <= value < table_size)
        :complexity: O(K) where K is the size of the key
        """
        value = 0
        a = 31415
        for char in key:
            value = (ord(char) + a * value) % len(self.table)
            a = a * LinearProbeTable.DEFAULT_HASH_BASE % (len(self.table) - 1)
        return value

    def insert(self, key: str, data: T) -> None:
        """
        Utility method to call our setitem method
        :see: #__setitem__(self, key: str, data: T)
        """
        self[key] = data

    def __str__(self) -> str:
        """
        Returns all they key/value pairs in our hash table (no particular order)
        :complexity: O(N) where N is the table size
        """
        result = ""
        for item in self.table:
            if item is not None:
                (key, value) = item
                result += "(" + str(key) + "," + str(value) + ")\n"
        return result


class TestHashTable(unittest.TestCase):
    def setup(self):
        pass

    def test_init(self):
        dictionary = LinearProbeTable()
        self.assertEqual(len(dictionary), 0, "Dictionary should be empty")

    def test_is_empty(self):
        dictionary = LinearProbeTable()
        self.assertTrue(dictionary.is_empty())

        dictionary["test"] = "test"
        self.assertFalse(dictionary.is_empty())

    def test_is_full(self):
        dictionary = LinearProbeTable(10)
        self.assertFalse(dictionary.is_full())

        for i in range(10):
            dictionary[str(i)] = i
        self.assertTrue(dictionary.is_full())

    def test_hash(self):
        dictionary = LinearProbeTable(5)
        for i in range(10):
            dictionary[str(i)] = i

        for i in range(10):
            self.assertEqual(dictionary[str(i)], i, "Could not find item: " + str(i))

    def test_len(self):
        dictionary = LinearProbeTable(5)
        self.assertEqual(len(dictionary), 0, "Dictionary should be empty")

        for i in range(3):
            dictionary[str(i)] = i

        self.assertEqual(len(dictionary), 3, "Dictionary should contain 3 items")

    def test_del(self):
        dictionary = LinearProbeTable(5)
        for i in range(10):
            dictionary[str(i)] = i

        for i in range(5):
            del dictionary[str(i)]

        for i in range(10):
            if i < 5:
                with self.assertRaises(KeyError):
                    _ = dictionary[str(i)]
            else:
                self.assertEqual(
                    dictionary[str(i)], i, "Could not find item: " + str(i)
                )

    def test_str(self):
        dictionary = LinearProbeTable(5)
        self.assertEqual(str(dictionary), "", "Dictionary should be empty")

        for i in range(5):
            dictionary[str(i)] = i
        for i in range(5):
            self.assertIn("(" + str(i) + "," + str(i) + ")", str(dictionary))


if __name__ == "__main__":
    unittest.main()
