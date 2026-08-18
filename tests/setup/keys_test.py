# -*- coding: UTF-8 -*-

'''
Module
    keys_test.py
Info
    Unit tests for GenNamedPipeBundleKeys class.
'''

from __future__ import annotations

import unittest
from types import MappingProxyType

from gen_named_pipe.setup.keys import GenNamedPipeBundleKeys


class TestGenNamedPipeBundleKeys(unittest.TestCase):

    def test_get_dependency_to_type(self) -> None:
        deps = GenNamedPipeBundleKeys.get_dependency_to_type()
        self.assertIsInstance(deps, MappingProxyType)
        self.assertIn(GenNamedPipeBundleKeys.DEPENDENCY_BASE, deps)
        self.assertIn(GenNamedPipeBundleKeys.DEPENDENCY_SERVICE, deps)
        self.assertIn(GenNamedPipeBundleKeys.DEPENDENCY_SUBPROCESSOR, deps)
        self.assertIn(GenNamedPipeBundleKeys.DEPENDENCY_CLI, deps)

    def test_get_option_to_type(self) -> None:
        opts = GenNamedPipeBundleKeys.get_option_to_type()
        self.assertIsInstance(opts, MappingProxyType)
        self.assertIn(GenNamedPipeBundleKeys.OPTION_INFO_FILE, opts)
