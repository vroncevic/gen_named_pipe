# -*- coding: UTF-8 -*-

'''
Module
    registry_test.py
Info
    Unit tests for GenNamedPipeBundleRegistry class.
'''

from __future__ import annotations

import unittest
from unittest.mock import Mock

from ats_utilities.base.setup.bundle import BaseBundle

from gen_named_pipe.core.service.iservice import IService
from gen_named_pipe.core.service.isubprocessor import ISubProcessor
from gen_named_pipe.infrastructure.cli.icli import ICLI
from gen_named_pipe.setup.bundle import GenNamedPipeBundle
from gen_named_pipe.setup.registry import GenNamedPipeBundleRegistry


class DummyService:

    def execute(self, *, params: object) -> object:
        return None

    def is_initialized(self) -> bool:
        return True


class DummySubProcessor:

    def run(self, *, params: object) -> dict[str, object]:
        return {}

    def is_initialized(self) -> bool:
        return True


class DummyCLI:

    def run(self) -> dict[str, object]:
        return {}

    def is_initialized(self) -> bool:
        return True


class TestGenNamedPipeBundleRegistry(unittest.TestCase):

    def test_create_bundle_success(self) -> None:
        mock_base = Mock(spec=BaseBundle)
        dummy_service = DummyService()
        dummy_subprocessor = DummySubProcessor()
        dummy_cli = DummyCLI()

        dependencies = {
            'base': mock_base,
            'service': dummy_service,
            'subprocessor': dummy_subprocessor,
            'cli': dummy_cli
        }
        
        bundle = GenNamedPipeBundleRegistry.create_bundle(dependencies)
        self.assertIsInstance(bundle, GenNamedPipeBundle)
        self.assertEqual(bundle.base, mock_base)

    def test_create_bundle_invalid_dependencies(self) -> None:
        with self.assertRaises(Exception):
            GenNamedPipeBundleRegistry.create_bundle(None)

    def test_get_version(self) -> None:
        self.assertEqual(GenNamedPipeBundleRegistry.get_version(), '1.2.0')
