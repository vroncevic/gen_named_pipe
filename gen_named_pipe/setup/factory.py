# -*- coding: UTF-8 -*-

'''
Module
    factory.py
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
    Factory for creating the gen_named_pipe bundle.
'''

from __future__ import annotations

from ats_utilities.base.setup.factory import BaseBundleFactory
from ats_utilities.base.setup.bundle import BaseBundle
from ats_utilities.base.setup.options import BaseBundleOptions
from ats_utilities.context.bundle import ContextBundle
from ats_utilities.context.factory import ContextBundleFactory

from gen_named_pipe.setup.bundle import GenNamedPipeBundle
from gen_named_pipe.setup.options import GenNamedPipeBundleOptions
from gen_named_pipe.setup.registry import GenNamedPipeBundleRegistry
from gen_named_pipe.setup.dependencies import GenNamedPipeBundleDependencies
from gen_named_pipe.setup.opt_validator import GenNamedPipeBundleOptionsValidator
from gen_named_pipe.setup.keys import GenNamedPipeBundleKeys
from gen_named_pipe.core.service.engine import Service
from gen_named_pipe.infrastructure.subprocessor import SubProcessor
from gen_named_pipe.infrastructure.cli.engine import CLI
from gen_named_pipe.infrastructure.cli.setup.bundle import CLIBundle
from gen_named_pipe.infrastructure.cli.setup.dependencies import CLIBundleDependencies
from gen_named_pipe.infrastructure.cli.setup.registry import CLIBundleRegistry
from gen_named_pipe.infrastructure.command.command import CommandBundle
from gen_named_pipe.infrastructure.command.gen_named_pipe_command_definition import GenNamedPipeCommandDefinition
from gen_named_pipe.infrastructure.command.gen_named_pipe_command_executor import GenNamedPipeCommandExecutor

__author__ = 'Vladimir Roncevic'
__copyright__ = '(C) 2026, https://vroncevic.github.io/gen_named_pipe'
__credits__ = ['Vladimir Roncevic', 'Python Software Foundation']
__license__ = 'https://github.com/vroncevic/gen_named_pipe/blob/dev/LICENSE'
__version__ = '1.0.5'
__maintainer__ = 'Vladimir Roncevic'
__email__ = 'elektron.ronca@gmail.com'
__status__ = 'Updated'


class GenNamedPipeBundleFactory:
    '''
        Factory for creating the gen_named_pipe bundle.

        It defines:

            :attributes:
                | _info_file - Path to the gen_named_pipe info file.
            :methods:
                | create_bundle - Creates the gen_named_pipe bundle with optional pre-configured options.
    '''

    _info_file: str = 'gen_named_pipe/infrastructure/config/gen_named_pipe.cfg'

    @classmethod
    def create_bundle(cls, options: GenNamedPipeBundleOptions | None = None) -> GenNamedPipeBundle:
        '''
            Creates the gen_named_pipe bundle with optional pre-configured options.

            :param options: The pre-configured options for the gen_named_pipe bundle.
            :return: The gen_named_pipe bundle.
            :exceptions:
                | ATSValueError: The gen_named_pipe bundle options must be provided and have proper values.
                | ATSTypeError:  The gen_named_pipe bundle options must be an instance of Mapping and its
                |                attributes must be instances of their respective types.
                | ATSValueError: The gen_named_pipe bundle dependencies must be provided and have proper values.
                | ATSTypeError:  The gen_named_pipe bundle dependencies must be an instance of Mapping and its
                |                attributes must be instances of their respective types.
                | ATSValueError: The gen_named_pipe bundle must be provided and have proper values.
                | ATSTypeError:  The gen_named_pipe bundle must be an instance of GenNamedPipeBundle and
                |                its attributes must be instances of their respective types.
        '''
        if options is not None:
            GenNamedPipeBundleOptionsValidator.validate(options)

        info_file = options.get(GenNamedPipeBundleKeys.OPTION_INFO_FILE) if options else cls._info_file

        context_bundle: ContextBundle = ContextBundleFactory.create_bundle()

        base_bundle: BaseBundle = BaseBundleFactory.create_bundle(
            options=BaseBundleOptions(
                info_file=info_file,
                use_generator=True,
                context_bundle=context_bundle
            )
        )

        subprocessor: SubProcessor = SubProcessor(generator=base_bundle.generation_manager)

        service: Service = Service(subprocessor=subprocessor)

        gen_named_pipe_definition: GenNamedPipeCommandDefinition = GenNamedPipeCommandDefinition()

        gen_named_pipe_bundle: CommandBundle = CommandBundle(
            definition=gen_named_pipe_definition,
            executor=GenNamedPipeCommandExecutor(gen_named_pipe_definition)
        )

        cli_bundle: CLIBundle = CLIBundleRegistry.create_bundle(
            dependencies=CLIBundleDependencies(
                service=service,
                parser=base_bundle.option_manager,
                commands=[gen_named_pipe_bundle]
            )
        )

        cli: CLI = CLI(cli_bundle)

        return GenNamedPipeBundleRegistry.create_bundle(
            dependencies=GenNamedPipeBundleDependencies(
                base=base_bundle,
                service=service,
                subprocessor=subprocessor,
                cli=cli
            )
        )
