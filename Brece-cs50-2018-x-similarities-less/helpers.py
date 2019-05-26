import re # module regular expression for funtion "lines"
from nltk.tokenize import sent_tokenize # module for function "sentences"

def lines(a, b):
    """Return lines in both a and b"""

    # TODO
    # create lists with each line of text as an element of the list
    listA = re.split(r'\n\s*', a)
    listB = re.split(r'\n\s*', b)

    # match elements as a set
    match_set = set(listA).intersection(listB)

    # convert set into a list
    match = list(match_set)

    return match


def sentences(a, b):
    """Return sentences in both a and b"""

    # TODO
    listA = sent_tokenize(a, language='english')
    listB = sent_tokenize(b, language='english')

    # match elements as a set
    match_set = set(listA).intersection(listB)

    # convert set into a list
    match = list(match_set)

    return match


def substrings(a, b, n):
    """Return substrings of length n in both a and b"""

    # TODO

    # store substrings in lists
    listA = list()
    listB = list()

    for i in range(len(a) - n+1):
        listA.append(a[i:n+i])


    for i in range(len(b) - n+1):
        listB.append(b[i:n+i])

    # save substrings of each list element in a set
    match_set = set(listA).intersection(listB)

    # convert set into a list
    match = list(match_set)

    return match
