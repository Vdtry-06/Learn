class Subject:
    def __init__(self, id, name, form):
        self.id = id
        self.name = name
        self.form = form

    def getId(self):
        return self.id

    def __str__(self):
        return f"{self.id} {self.name} {self.form}"

def main():
    subjects = []
    for t in range(int(input())):
        id = input()
        name = input()
        form = input()
        subjects.append(Subject(id, name, form))
    subjects.sort(key = lambda id: id.getId())
    for subject in subjects:
        print(subject)

main()