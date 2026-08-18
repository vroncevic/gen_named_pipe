# -*- coding: UTF-8 -*-

'''
Module
    registry.py
Copyright
    Copyright (C) 2026 Vladimir Roncevic <elektron.ronca@gmail.com>
    gen_named_pipe is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    gen_named_pipe is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
    See the GNU General Public License for more details.
    You should have received a copy of the GNU General Public License along
    with this program. If not, see <http://www.gnu.org/licenses/>.
Info
    Encapsulates core gen_named_pipe components for simplification of gen_named_pipe bundle.
'''

from __future__ import annotations

from ats_utilities.base.setup.bundle import BaseBundle

from gen_named_pipe.core.service.iservice import IService
from gen_named_pipe.core.service.isubprocessor import ISubProcessor
from gen_named_pipe.infrastructure.cli.icli import ICLI
from gen_named_pipe.setup.bundle import GenNamedPipeBundle
from gen_named_pipe.setup.validator import GenNamedPipeBundleValidator
from gen_named_pipe.setup.keys import GenNamedPipeBundleKeys
from gen_named_pipe.setup.dependencies import GenNamedPipeBundleDependencies
from gen_named_pipe.setup.dep_validator import GenNamedPipeBundleDependenciesValidator

__author__ = 'Vladimir Roncevic'
__copyright__ = '(C) 2026, https://vroncevic.github.io/gen_named_pipe'
__credits__ = ['Vladimir Roncevic', 'Python Software Foundation']
__license__ = 'https://github.com/vroncevic/gen_named_pipe/blob/dev/LICENSE'
__version__ = '1.2.0'
__maintainer__ = 'Vladimir Roncevic'
__email__ = 'elektron.ronca@gmail.com'
__status__ = 'Updated'


class GenNamedPipeBundleRegistry:
    '''
        Encapsulates core gen_named_pipe components for simplification of gen_named_pipe bundle.

        It defines:

            :methods:
                | create_bundle - Creates the gen_named_pipe bundle.
                | get_version - Returns the registry version.
    '''

    @classmethod
    def create_bundle(cls, dependencies: GenNamedPipeBundleDependencies) -> GenNamedPipeBundle:
        '''
            Creates the gen_named_pipe bundle.

            :param dependencies: The gen_named_pipe bundle dependencies.
            :return: The gen_named_pipe bundle.
            :exceptions:
                | ATSValueError: The gen_named_pipe bundle dependencies must be provided and have proper values.
                | ATSTypeError:  The gen_named_pipe bundle dependencies must be an instance of Mapping and its
                |                attributes must be instances of their respective types.
                | ATSValueError: The gen_named_pipe bundle must be provided and have proper values.
                | ATSTypeError:  The gen_named_pipe bundle must be an instance of GenNamedPipeBundle and
                |                its attributes must be instances of their respective types.
        '''
        GenNamedPipeBundleDependenciesValidator.validate(dependencies)

        base: BaseBundle | None = dependencies.get(GenNamedPipeBundleKeys.DEPENDENCY_BASE) if dependencies else None
        service: IService | None = dependencies.get(GenNamedPipeBundleKeys.DEPENDENCY_SERVICE) if dependencies else None
        subprocessor: ISubProcessor | None = dependencies.get(GenNamedPipeBundleKeys.DEPENDENCY_SUBPROCESSOR) if dependencies else None
        cli: ICLI | None = dependencies.get(GenNamedPipeBundleKeys.DEPENDENCY_CLI) if dependencies else None

        bundle: GenNamedPipeBundle = GenNamedPipeBundle(base=base, service=service, subprocessor=subprocessor, cli=cli)

        GenNamedPipeBundleValidator.validate(bundle)

        return bundle

    @classmethod
    def get_version(cls) -> str:
        '''
            Returns the registry version.

            :return: The registry version.
            :exceptions: None.
        '''
        return __version__
