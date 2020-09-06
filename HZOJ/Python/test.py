params = {"plan_id": 1, "show_all": 2, "days": 4}

valid = []

result = 0

valid.append(params["show_all"])
valid.append(params["days"])
valid.append(params["show_all"] | params["plan_id"])
valid.append(params["days"] | params["plan_id"])

print(valid)

result = params["plan_id"] | params["show_all"]
print("result:" + result)

print(result in valid)
