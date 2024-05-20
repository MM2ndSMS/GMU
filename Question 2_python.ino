import math

def vector_inner_product(vector_a, vector_b):
    """
    두 벡터의 내적을 계산합니다.
    
    Parameters:
    vector_a, vector_b: 두 벡터 (리스트 형태로 입력)
    
    Returns:
    inner_product: 벡터 내적의 결과
    """
    inner_product = vector_a[0] * vector_b[0] + vector_a[1] * vector_b[1]
    return inner_product

def calculate_distance(a, b, c, x0, y0):
    """
    주어진 점 (x0, y0)에서 직선 ax + by + c = 0 까지의 거리를 계산합니다.
    
    Parameters:
    a, b, c: 직선의 방정식 계수
    x0, y0: 점의 좌표
    
    Returns:
    r: 점에서 직선까지의 거리
    """
    # 법선(평명에서의 해당 선에 대한 방향) 벡터와 점 벡터의 내적을 이용하여 분자를 계산합니다.
    normal_vector = (a, b)
    point_vector = (x0, y0)
    numerator = abs(vector_inner_product(normal_vector, point_vector) + c)
    
    # 법선(평명에서의 해당 선에 대한 방향) 벡터의 크기를 계산하여 분모를 구합니다.
    denominator = math.sqrt(vector_inner_product(normal_vector, normal_vector))
    
    # 수직 거리 r을 계산합니다.
    r = numerator / denominator
    
    return r

def find_perpendicular_point(a, b, x0, y0, r):
    """
    점 (x0, y0)에서 직선에 수직으로 떨어진 점 (xc, yc)를 구합니다.
    
    Parameters:
    a, b: 직선의 방정식 계수 (직선의 방향 벡터)
    x0, y0: 점의 좌표
    r: 점에서 직선까지의 거리
    
    Returns:
    xc, yc: 수직으로 떨어진 점의 좌표
    """
    # 방향 벡터의 크기를 구합니다.
    magnitude = math.sqrt(a**2 + b**2)
    
    # 방향 벡터의 단위 벡터를 구합니다.
    unit_vector = (a / magnitude, b / magnitude)
    
    # 단위 벡터에 거리를 곱해서 새로운 점 (xc, yc)을 구합니다.
    xc = x0 + unit_vector[0] * r
    yc = y0 + unit_vector[1] * r
    
    return xc, yc

def main():
    # 사용자로부터 입력 받기
    a = float(input("직선의 방정식 계수 a를 입력하세요: "))
    b = float(input("직선의 방정식 계수 b를 입력하세요: "))
    c = float(input("직선의 방정식 계수 c를 입력하세요: "))
    x0 = float(input("점의 x 좌표를 입력하세요: "))
    y0 = float(input("점의 y 좌표를 입력하세요: "))

    # 점 (x0, y0)에서 직선까지의 거리 r을 계산합니다.
    r = calculate_distance(a, b, c, x0, y0)
    print(f"점 ({x0}, {y0})에서 직선까지의 거리: {r}")

    # 수직으로 떨어진 점 (xc, yc)를 구합니다.
    xc, yc = find_perpendicular_point(a, b, x0, y0, r)
    print(f"수직으로 떨어진 점: ({xc}, {yc})")

    # 수직 거리가 맞는지 확인합니다.
    distance_check = math.sqrt((xc - x0)**2 + (yc - y0)**2)
    print(f"계산된 거리 확인: {distance_check}")

if __name__ == '__main__':
    main()
