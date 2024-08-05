import csv
import sys

def main():
    # Check for command-line usage
    if len(sys.argv) != 3:
        print("INVALID FILES")
        return

    # Read database file into a variable
    datab = []
    with open(sys.argv[1], 'r') as db:
        reader = csv.DictReader(db)
        for row in reader:
            datab.append(row)

    # Read DNA sequence file into a variable
    with open(sys.argv[2], 'r') as sequence:
        seq = sequence.readline().strip()

    # Find longest match of each STR in DNA sequence
    final = {}
    keys = list(datab[0].keys())
    for key in keys:
        if key != "name":
            final[key] = longest_match(seq, key)

    # Check database for matching profiles
    for dict in datab:
        if check(dict, final):
            print(dict['name'])
            return

    print('No match')
    return

def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    for i in range(sequence_length):
        count = 0
        while True:
            start = i + count * subsequence_length
            end = start + subsequence_length

            if sequence[start:end] == subsequence:
                count += 1
            else:
                break

        longest_run = max(longest_run, count)

    return longest_run

def check(dict, final):
    for key in final:
        if int(dict[key]) != final[key]:
            return False

    return True


main()
