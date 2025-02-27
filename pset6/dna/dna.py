import csv
import sys


def main():

    # TODO: Check for command-line usage
    if len(sys.argv) <= 1:
        print("No arguments were given")
        return 1
    elif len(sys.argv) > 3:
        print("More arguments were given")
        return 1

    # TODO: Read database file into a variable
    with open(sys.argv[1], 'r') as csvfile:
        database = list(csv.DictReader(csvfile))

    # TODO: Read DNA sequence file into a variable
    with open(sys.argv[2], 'r') as dnafile:
        dna_sequence = dnafile.read()

    # Identify STR patterns from database headers
    str_patterns = list(database[0].keys())[1:]

    # Calculate STR counts in DNA sequence
    dna_str_counts = {}
    for pattern in str_patterns:
        dna_str_counts[pattern] = longest_match(dna_sequence, pattern)

    # Match DNA profile
    for person in database:
        # Compare STR counts, skipping name column
        if all(int(person[pattern]) == dna_str_counts[pattern] for pattern in str_patterns):
            print(person['name'])
            return

    # If no match found
    print("No match")
    return 2


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


if __name__ == "__main__":
    main()
