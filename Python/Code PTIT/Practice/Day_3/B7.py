class Apart:
    def __init__(self, id, name):
        self.id = id
        self.name = name

class Employee:
    FACTORS = {
        'A': [10, 12, 14, 20],
        'B': [10, 11, 13, 16],
        'C': [9, 10, 12, 14],
        'D': [8, 9, 11, 13]
    }

    def __init__(self, id, name, salary, quantity):
        self.id = id
        self.name = name
        self.salary = int(salary)
        self.quantity = int(quantity)
        self.type = id[0]
        self.years = int(id[1:3])
        self.department_id = id[3:]

    def getCoefficient(self):
        if self.years >= 16:
            return Employee.FACTORS[self.type][3]
        elif self.years >= 9:
            return Employee.FACTORS[self.type][2]
        elif self.years >= 4:
            return Employee.FACTORS[self.type][1]
        else:
            return Employee.FACTORS[self.type][0]

    def calculateSalary(self):
        return self.salary * self.quantity * self.getCoefficient()

apartments = {}
n_apartments = int(input())

for _ in range(n_apartments):
    apart_id, apart_name = input().split(maxsplit=1)
    apartments[apart_id] = apart_name

employees = []
n_employees = int(input())

for _ in range(n_employees):
    emp_id = input().strip()
    emp_name = input().strip()
    emp_salary = input().strip()
    emp_quantity = input().strip()
    employees.append(Employee(emp_id, emp_name, emp_salary, emp_quantity))


for emp in employees:
    department_name = apartments[emp.department_id]
    total_salary = emp.calculateSalary() * 1000
    print(f"{emp.id} {emp.name} {department_name} {total_salary}")
