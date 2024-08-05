from cs50 import get_int
import sys

num = get_int("What's the number: ")
len = (len(str(num)))

list1 = []  # contains all the number to be added at the end
if len % 2 == 0:
    for i in range(int(len/2)):
        num2 = num % (10**(2*(i + 1)))
        list1.append(int((num2/10) + num2 % 10))

else:
    for i in range(int((len-1)/2)):
        list1.append(num % (10**(2*i + 1)))

checksum = sum(list1)

# sort of main function
if checksum % 10 == 0:
    if len == 15:
        if int(num/(10**13)) in (34, 37):
            print("AMEX")
            sys.exit(0)
    if len == 16:
        if int(num/(10**14)) in (51, 52, 53, 54, 55):
            print("MASTERCARD")
            sys.exit(0)
        if int(num/(10**15)) == 4:
            print("VISA")
            sys.exit(0)
    if len == 13:
        if int(num/(10**12)) == 4:
            print("VISA")
            sys.exit(0)

print("INVALID")
