#!/usr/bin/env python

import os
import subprocess


def main():
    output_dir = os.path.join(os.path.join('build', 'output'))
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)
    generated_header_filename = os.path.join(output_dir, 'nf_generated_header.h')
    generated_header = open(generated_header_filename, 'w')
    generated_header.write('// This is a generated header from generate-version.py\n')
    cwd = os.getcwd()
    print 'PYTHON CWD: ' + cwd
    git_count = subprocess.check_output(['git', 'rev-list', '--count', 'HEAD'], cwd = cwd)
    git_describe = subprocess.check_output(['git', 'describe', '--always'], cwd = cwd)
    generated_header.write('#define SMARTPLAYER_VERSION "' + git_count.strip() + '-' + git_describe.strip() + '"\n')


if __name__ == "__main__":
    main()
