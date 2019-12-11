import os
import subprocess
import time

from config import TEST_INPUTS_DIR, TEST_OUTPUTS_DIR

def get_test_files():
    return os.listdir(TEST_INPUTS_DIR)

def clean_str(s):
    lines = s.split('\n')
    return '\n'.join([line.replace('marcella', '').replace('glins', '') for line in lines if 'WARNING' not in line and '$' not in line])

def get_test(fn):
    def test_func():
        CORRECT_OUTPUT = ''
        with open (TEST_OUTPUTS_DIR + fn + '_output', 'rb') as f:
            CORRECT_OUTPUT = clean_str(f.read().decode('utf-8'))

        output = subprocess.run(['expect', TEST_INPUTS_DIR + fn], stdout=subprocess.PIPE).stdout.decode('utf-8')
        output = clean_str(output)
        
        res = CORRECT_OUTPUT == output
        if res == False:
            print(CORRECT_OUTPUT)
            print()
            print(output)
            input()
        return res

    return (fn, test_func)

def get_all_tests():
    tests = []
    for fn in get_test_files():
        tests.append(get_test(fn))
    return tests

def run_test(fn, func):
    START_TIME = time.time()
    res = func()
    END_TIME = time.time()
    return [fn, res, END_TIME - START_TIME]

def run_all_tests():
    tests = get_all_tests()
    size = len(tests)
    print('Tests found: {}'.format(size))
    print('Starting...')
    print('--------------------------------------')

    positive_tests = 0
    for index, (fn, func) in enumerate(tests):
        fn, res, dt = run_test(fn, func)
        if res:
            positive_tests += 1
        print('[{}/{}] {} :: {} ({:.2f}s)'.format(index + 1, size, fn, 'SUCCESS' if res else 'FAIL', dt))
    print('--------------------------------------')
    
    if positive_tests == size:
        print('All tests passed!')
    else:
        print('{:.2f}% of tests passed'.format(100.0 * positive_tests / size))

def recalculate_all_outputs():
    for fn in get_test_files():
        print('Running {}...'.format(fn))
        output = subprocess.run(['expect', TEST_INPUTS_DIR + fn], stdout=subprocess.PIPE).stdout
        
        with open (TEST_OUTPUTS_DIR + fn + '_output', 'wb') as f:
            f.write(output)

if __name__ == '__main__':
    run_all_tests()  
    # recalculate_all_outputs()