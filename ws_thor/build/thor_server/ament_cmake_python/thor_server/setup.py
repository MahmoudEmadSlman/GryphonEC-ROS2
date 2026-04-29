from setuptools import find_packages
from setuptools import setup

setup(
    name='thor_server',
    version='0.0.0',
    packages=find_packages(
        include=('thor_server', 'thor_server.*')),
)
