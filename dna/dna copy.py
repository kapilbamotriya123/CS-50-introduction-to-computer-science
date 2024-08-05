import csv
import sys



def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        print("INVALID FILES")
        return
    '''defining the two list where data will be read'''
    datab = [] #for storing the each persons dna info

    # TODO: Read database file into a variable
    with open(sys.argv[1], 'r') as db:
        reader = csv.DictReader(db)
        for row in reader:
            datab.append(row)

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], 'r') as sequence:
        seq = sequence.readline()

    # print karwa kar check kar rhe hai
    # TODO: Find longest match of each STR in DNA sequence
    max_key = 0
    key_final = ''
    final = {}
    keys = list(datab[1].keys())
    for key in keys:
        if key != "name":
            x = longest_match(seq, key)
            if x > max_key:
                key_final = key
                max_key = x
                final[key_final] = x

    # TODO: Check database for matching profiles

    for dict in (datab):
        if check(dict,final) == True:
            return
    print('No match')
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run

def check(dict,final):
    for key in final:
        if int(dict[key]) != final[key] or final[key] < 2:
            return False

    print(dict['name'])
    return True


main()
