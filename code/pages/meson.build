dir = include_directories('.')

run_command(['python3', '..' / 'tools' / 'generate-runner.py'], check: true)
cards = run_command(['python3', '..' / 'tools' / 'scan-pages.py'], check: true)

test_c   = ['unit_runner.c']
test_cases = [cards.stdout().strip().split('\n')] # wildcard trick for the codelabs

pizza = executable('pizza', test_c, test_cases, include_directories: dir, dependencies: [dependency('fossil-test')])
test('Pizza test', pizza)
