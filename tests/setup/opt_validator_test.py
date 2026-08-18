# -*- coding: UTF-8 -*-

'''
Module
    opt_validator_test.py
Info
    Unit tests for GenNamedPipeBundleOptionsValidator class.
'''

from __future__ import annotations

import unittest

from gen_named_pipe.setup.opt_validator import GenNamedPipeBundleOptionsValidator


class TestGenNamedPipeBundleOptionsValidator(unittest.TestCase):

    def test_validate_success(self) -> None:
        options = {'info_file': 'some_path'}
        GenNamedPipeBundleOptionsValidator.validate(options)

    def test_validate_none(self) -> None:
        with self.assertRaises(Exception):
            GenNamedPipeBundleOptionsValidator.validate(None)

    def test_validate_invalid_type(self) -> None:
        with self.assertRaises(Exception):
            GenNamedPipeBundleOptionsValidator.validate("not_a_mapping")

    def test_validate_invalid_option_type(self) -> None:
        with self.assertRaises(Exception):
            options = {'info_file': 123}
            GenNamedPipeBundleOptionsValidator.validate(options)

    def test_is_valid_success(self) -> None:
        options = {'info_file': 'some_path'}
        self.assertTrue(GenNamedPipeBundleOptionsValidator.is_valid(options))

    def test_is_valid_failure(self) -> None:
        self.assertFalse(GenNamedPipeBundleOptionsValidator.is_valid(None))
        self.assertFalse(GenNamedPipeBundleOptionsValidator.is_valid("not_a_mapping"))
        self.assertFalse(GenNamedPipeBundleOptionsValidator.is_valid({'info_file': 123}))
