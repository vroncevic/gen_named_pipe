Generate Named Pipe
--------------------

**gen_named_pipe** is framework for generation Named Pipe modules.

Developed in `python <https://www.python.org/>`_ code: **100%**.

The README is used to introduce the modules and provide instructions on
how to install the modules, any machine dependencies it may have and any
other information that should be provided before the modules are installed.

|Python package| |GitHub issues| |Documentation Status| |GitHub contributors|

.. |Python package| image:: https://github.com/vroncevic/gen_named_pipe/workflows/Python%20package%20gen_named_pipe/badge.svg
   :target: https://github.com/vroncevic/gen_named_pipe/workflows/Python%20package%20gen_named_pipe/badge.svg?branch=master

.. |GitHub issues| image:: https://img.shields.io/github/issues/vroncevic/gen_named_pipe.svg
   :target: https://github.com/vroncevic/gen_named_pipe/issues

.. |GitHub contributors| image:: https://img.shields.io/github/contributors/vroncevic/gen_named_pipe.svg
   :target: https://github.com/vroncevic/gen_named_pipe/graphs/contributors

.. |Documentation Status| image:: https://readthedocs.org/projects/gen_named_pipe/badge/?version=latest
   :target: https://gen_named_pipe.readthedocs.io/projects/gen_named_pipe/en/latest/?badge=latest

.. toctree::
   :maxdepth: 4
   :caption: Contents

   self
   modules

Installation
-------------

|Install Python2 Package| |Install Python3 Package|

.. |Install Python2 Package| image:: https://github.com/vroncevic/gen_named_pipe/workflows/Install%20Python2%20Package%20gen_named_pipe/badge.svg
   :target: https://github.com/vroncevic/gen_named_pipe/workflows/Install%20Python2%20Package%20gen_named_pipe/badge.svg?branch=master

.. |Install Python3 Package| image:: https://github.com/vroncevic/gen_named_pipe/workflows/Install%20Python3%20Package%20gen_named_pipe/badge.svg
   :target: https://github.com/vroncevic/gen_named_pipe/workflows/Install%20Python3%20Package%20gen_named_pipe/badge.svg?branch=master

Navigate to release `page`_ download and extract release archive.

.. _page: https://github.com/vroncevic/gen_named_pipe/releases

To install package type the following

.. code-block:: bash

    tar xvzf gen_named_pipe-x.y.z.tar.gz
    cd gen_named_pipe-x.y.z/
    # python2
    pip install -r requirements.txt
    python setup.py install_lib
    python setup.py install_data
    python setup.py install_egg_info
    # pyton3
    pip3 install -r requirements.txt
    python3 setup.py install_lib
    python setup.py install_data
    python3 setup.py install_egg_info

You can use Docker to create image/container, or You can use pip to install

.. code-block:: bash

    # python2
    pip install gen-named-pipe
    # python3
    pip3 install gen-named-pipe

|GitHub docker checker|

.. |GitHub docker checker| image:: https://github.com/vroncevic/gen_named_pipe/workflows/gen_named_pipe%20docker%20checker/badge.svg
   :target: https://github.com/vroncevic/gen_named_pipe/actions?query=workflow%3A%21gen_named_pipe+docker+checker%22

Dependencies
-------------

**gen_named_pipe** requires next modules and libraries

* `ats-utilities - Python App/Tool/Script Utilities <https://pypi.org/project/ats-utilities/>`_

Framework structure
--------------------

**gen_named_pipe** is based on OOP

.. image:: https://raw.githubusercontent.com/vroncevic/gen_named_pipe/dev/docs/gen_named_pipe_flow.png

Framework structure

.. code-block:: bash

    gen_named_pipe/
    ├── conf/
    │   ├── gen_named_pipe.logo
    │   ├── gen_named_pipe.cfg
    │   ├── gen_named_pipe_util.cfg
    │   ├── project.yaml
    │   └── template/
    │       └── posix/
    │           ├── np_close.template
    │           ├── np_make.template
    │           ├── np_open.template
    │           ├── np_read.template
    │           ├── np.template
    │           └── np_write.template
    ├── __init__.py
    ├── log/
    │   └── gen_named_pipe.log
    ├── pro/
    │   ├── config/
    │   │   ├── __init__.py
    │   │   ├── pro_name.py
    │   │   └── template_dir.py
    │   ├── __init__.py
    │   ├── read_template.py
    │   └── write_template.py
    └── run/
        └── gen_named_pipe_run.py

Copyright and licence
----------------------

|License: GPL v3| |License: Apache 2.0|

.. |License: GPL v3| image:: https://img.shields.io/badge/License-GPLv3-blue.svg
   :target: https://www.gnu.org/licenses/gpl-3.0

.. |License: Apache 2.0| image:: https://img.shields.io/badge/License-Apache%202.0-blue.svg
   :target: https://opensource.org/licenses/Apache-2.0

Copyright (C) 2020 by `vroncevic.github.io/gen_named_pipe <https://vroncevic.github.io/gen_named_pipe>`_

**gen_named_pipe** is free software; you can redistribute it and/or modify
it under the same terms as Python itself, either Python version 2.x/3.x or,
at your option, any later version of Python 3 you may have available.

Lets help and support PSF.

|Python Software Foundation|

.. |Python Software Foundation| image:: https://raw.githubusercontent.com/vroncevic/gen_named_pipe/dev/docs/psf-logo-alpha.png
   :target: https://www.python.org/psf/

|Donate|

.. |Donate| image:: https://www.paypalobjects.com/en_US/i/btn/btn_donateCC_LG.gif
   :target: https://psfmember.org/index.php?q=civicrm/contribute/transact&reset=1&id=2

Indices and tables
------------------

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`
