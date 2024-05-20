import sympy as sp

# 두 직선의 방정식
a, b, c, d, e, f = sp.symbols('a b c d e f')
x, y = sp.symbols('x y')

# 첫 번째 직선
line1 = a*x + b*y + c

# 두 번째 직선
line2 = d*x + e*y + f

# 두 직선의 교점
x0, y0 = sp.symbols('x0 y0')

# 두 직선의 방정식에 교점 대입하여 연립방정식 풀기
solution = sp.solve([line1.subs({x: x0, y: y0}), line2.subs({x: x0, y: y0})], (x0, y0))

# 교점 좌표 구하기
x0_val, y0_val = solution[x0], solution[y0]

# 각 이등분선 구하기
m1, m2 = -c/b, -f/e  # 직선의 기울기
theta = sp.atan(sp.Abs((m1 - m2) / (1 + m1 * m2)))  # 두 직선이 이루는 각
m = sp.tan(theta / 2)  # 각 이등분선의 기울기

# 중심 좌표 구하기
h = (a * e * (b**2 * f + c * d * e - c * e * f) + b * d * (a * d * e - b * c * e + b * d * f)) / ((a**2 + b**2) * (d**2 + e**2))
k = (b * d * (a**2 * f + b * c * d - b * d * f) + a * e * (a * d * e - b * c * e + b * d * f)) / ((a**2 + b**2) * (d**2 + e**2))

# 반지름 구하기
r = sp.sqrt((a * x0_val + b * y0_val + c)**2 / (a**2 + b**2))

# 원의 방정식 출력
circle_equation = (x - h)**2 + (y - k)**2 - r**2
print("원의 방정식:", circle_equation)
