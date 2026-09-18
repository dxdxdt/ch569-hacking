#!/bin/env python3
def merge_vals(a: str, b: str) -> str:
	ret = list[str]()

	for i in range(max(len(a), len(b))):
		if len(a) <= i or a[i].isspace():
			ret.append(b[i])
		elif len(b) <= i or b[i].isspace():
			ret.append(a[i])
		elif a[i] == b[i]:
			ret.append(a[i])
		else:
			raise ValueError(a, b, ret)

	return ''.join(ret)

out = list[str]()
cur_key: str = None
cur_line: str = None
i = 0

while True:
	try:
		line = input()
		if not line or line.isspace():
			continue
	except EOFError:
		break

	cut = line.split(' ', 1)
	if cur_key is None:
		cur_key = cut[0]
		cur_line = line
	elif cur_key != cut[0]:
		out.append('|%2d%s' % (i, cur_line,))
		cur_line = line
		cur_key = cut[0]
		i += 1
	else:
		cur_line = merge_vals(cur_line, line)
if cur_line is not None:
	out.append('|%d%s' % (i, cur_line,))
	cur_line = None
	i += 1

print('\n'.join(out))
