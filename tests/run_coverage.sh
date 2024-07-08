#!/bin/bash
#
# @brief   gen_named_pipe
# @version v1.0.1
# @date    Sat Aug 1 07:52:38 2020
# @company None, free software to use 2020
# @author  Vladimir Roncevic <elektron.ronca@gmail.com>
#

rm -rf htmlcov gen_named_pipe_coverage.xml gen_named_pipe_coverage.json .coverage
rm -rf fresh_new/ full_simple_new/ latest_pro/ simple_read/ simple_write/
ats_coverage_run.py -n gen_named_pipe -p ../README.md
rm -rf fresh_new/ full_simple_new/ latest_pro/ simple_read/ simple_write/
python3 -m coverage run -m --source=../gen_named_pipe unittest discover -s ./ -p '*_test.py' -vvv
python3 -m coverage html -d htmlcov
python3 -m coverage xml -o gen_named_pipe_coverage.xml 
python3 -m coverage json -o gen_named_pipe_coverage.json
python3 -m coverage report --format=markdown -m
