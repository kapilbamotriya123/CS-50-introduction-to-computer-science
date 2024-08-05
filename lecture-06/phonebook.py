
people = {
    "Kapil": "8305387299",
    "Shubham": "9754716854",
    "Mridul": "2345678903",
}

name = input("name: ")
if name in people:
        number = people[name]
        print(f"found {number}")
else:
    print("not found")
