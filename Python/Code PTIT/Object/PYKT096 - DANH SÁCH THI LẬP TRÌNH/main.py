cnt_attendee = 1
cnt_team = 1
class Team:
    def __init__(self, name, school):
        global cnt_team
        self.id = f"Team{cnt_team:02d}"
        self.name = name
        self.school = school

        cnt_team += 1

class Attendee:
    def __init__(self, name, o):
        global cnt_attendee
        self.id = f"C{cnt_attendee:03d}"
        self.name = name
        self.o = o
        cnt_attendee += 1

    def __str__(self):
        return f"{self.id} {self.name} {self.o.name} {self.o.school}"

teams = []
mp = {}
for t in range(int(input())):
    team = Team(input(), input())
    mp[team.id] = team

attendees = []
for t in range(int(input())):
    attendees.append(Attendee(input(), mp[input()]))

attendees.sort(key = lambda x: x.name)

for attendee in attendees:
    print(attendee)
