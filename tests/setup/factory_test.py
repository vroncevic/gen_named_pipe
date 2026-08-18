# -*- coding: UTF-8 -*-

'''
Module
    factory_test.py
Info
    Unit tests for GenNamedPipeBundleFactory class.
'''

from __future__ import annotations

import unittest

from gen_named_pipe.setup.bundle import GenNamedPipeBundle
from gen_named_pipe.setup.factory import GenNamedPipeBundleFactory


class TestGenNamedPipeBundleFactory(unittest.TestCase):

    def test_create_bundle_default(self) -> None:
        bundle = GenNamedPipeBundleFactory.create_bundle()
        self.assertIsInstance(bundle, GenNamedPipeBundle)

    def test_create_bundle_with_options(self) -> None:
        options = {'info_file': 'gen_named_pipe/infrastructure/config/gen_named_pipe.cfg'}
        bundle = GenNamedPipeBundleFactory.create_bundle(options)
        self.assertIsInstance(bundle, GenNamedPipeBundle)

    def test_create_bundle_invalid_options(self) -> None:
        options = {'info_file': 123}
        with self.assertRaises(Exception):
            GenNamedPipeBundleFactory.create_bundle(options)

    def test_get_version(self) -> None:
        self.assertEqual(GenNamedPipeBundleFactory.get_version(), '1.2.0')
