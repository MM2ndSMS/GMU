import numpy as np

def calculate_R(a1, b1, C1, a2, b2, C2, x0=0, y0=0):
    # 방향 벡터를 정의합니다
    d1 = np.array([-b1, a1])
    d2 = np.array([-b2, a2])

    # 두 벡터의 내적과 크기를 계산합니다
    dot_product = np.dot(d1, d2)
    magnitude_d1 = np.linalg.norm(d1)
    magnitude_d2 = np.linalg.norm(d2)

    # 두 벡터 사이의 각도를 계산합니다
    cos_theta = dot_product / (magnitude_d1 * magnitude_d2)
    theta = np.arccos(cos_theta)
    tan_theta = np.tan(theta)

    # 두 직선의 교점을 구합니다
    # 행렬식을 이용하여 교점 (x_i, y_i)를 계산합니다
    A = np.array([[a1, b1], [a2, b2]])
    C = np.array([-C1, -C2])
    intersection = np.linalg.solve(A, C)
    x_i, y_i = intersection

    # 원점 (x0, y0)에서 교점 (x_i, y_i)까지의 거리를 계산합니다
    distance = np.sqrt((x_i - x0)**2 + (y_i - y0)**2)

    # 최종 R 값을 계산합니다
    R = tan_theta * distance

    # 결과를 반환합니다
    return R, x_i, y_i, distance

# 예시로 사용자로부터 입력 값을 받습니다
a1 = float(input("a1 값을 입력하세요: "))
b1 = float(input("b1 값을 입력하세요: "))
C1 = float(input("C1 값을 입력하세요: "))
a2 = float(input("a2 값을 입력하세요: "))
b2 = float(input("b2 값을 입력하세요: "))
C2 = float(input("C2 값을 입력하세요: "))

# R 값 계산
R, x_i, y_i, distance = calculate_R(a1, b1, C1, a2, b2, C2)

# 결과 출력
print(f"교점: (x_i, y_i) = ({x_i}, {y_i})")
print(f"원점에서 교점까지의 거리: {distance}")
print(f"R 값: {R}")
