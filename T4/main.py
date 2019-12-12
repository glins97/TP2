import os
import subprocess
import time
import sys

from config import TEST_INPUTS_DIR, TEST_OUTPUTS_DIR

def get_test_files():
    return os.listdir(TEST_INPUTS_DIR)

def clean_str(s):
    lines = s.split('\n')
    return '\n'.join([line.replace('marcella', '').replace('glins', '') for line in lines if 'WARNING' not in line and '$' not in line and '@' not in line])

def get_test(fn):
    def test_func():
        CORRECT_OUTPUT = ''
        with open (TEST_OUTPUTS_DIR + fn + '_output', 'rb') as f:
            CORRECT_OUTPUT = clean_str(f.read().decode('utf-8'))

        output = subprocess.run(['expect', TEST_INPUTS_DIR + fn], stdout=subprocess.PIPE).stdout.decode('utf-8')
        output = clean_str(output)
        
        return CORRECT_OUTPUT == output

    return (fn, test_func)

def get_all_tests():
    tests = []
    for fn in get_test_files():
        tests.append(get_test(fn))
    return tests

def run_test(func):
    START_TIME = time.time()
    res = func()
    END_TIME = time.time()
    return [res, END_TIME - START_TIME]

def _run_single_test(fn):
    _, func = get_test(fn)
    res, dt = run_test(func)
    print('  [{}/{}] {} :: {} ({:.2f}s)'.format(1, 1, fn, 'SUCCESS' if res else 'FAIL', dt))

def _run_all_tests():
    tests = get_all_tests()
    size = len(tests)
    print('Tests found: {}'.format(size))
    print('Starting...')
    print('--------------------------------------')

    positive_tests = 0
    for index, (fn, func) in enumerate(tests):
        res, dt = run_test(func)
        if res:
            positive_tests += 1
        print('  [{}/{}] {} :: {} ({:.2f}s)'.format(index + 1, size, fn, 'SUCCESS' if res else 'FAIL', dt))
    print('--------------------------------------')
    
    if positive_tests == size:
        print('All tests passed!')
    else:
        print('{:.2f}% of tests passed'.format(100.0 * positive_tests / size))

def _recalculate_all_outputs():
    for fn in get_test_files():
        print('Running {}...'.format(fn))
        output = subprocess.run(['expect', TEST_INPUTS_DIR + fn], stdout=subprocess.PIPE).stdout
        
        with open (TEST_OUTPUTS_DIR + fn + '_output', 'wb') as f:
            f.write(output)

def _list_all_tests():
    print('Avaiable tests are: ')
    for index, fn in enumerate(get_test_files()):
        print('  {}. {}'.format(index + 1, fn))

def _help():
    print('Please enter a parameter. Choices are:')
    print('  (-h) or (--help)\t- this menu;')
    print('  (-l) or (--list)\t- show all tests;')
    print('  (-a) or (--all)\t- run all tests;')
    print('  (-t <test_filename>)\t- run only test in specified filename;')
    print('\n')


if __name__ == '__main__':
    if len(sys.argv) == 1 \
        or sys.argv[1] == '--help' or sys.argv[1] == '-h':
        _help()
    else:
        if sys.argv[1] == '-a' or sys.argv[1] == '--all': 
            _run_all_tests()  
        elif sys.argv[1] == '-t':
            _run_single_test(sys.argv[2])
        elif sys.argv[1] == '-l' or sys.argv[1] == '--list': 
            _list_all_tests()
        elif sys.argv[1] == '-r': 
            _recalculate_all_outputs()