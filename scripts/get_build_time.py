import datetime

def get_build_time():
    now = datetime.datetime.now()
    return now.strftime("%Y-%m-%d %H:%M:%S")

if __name__ == "__main__":
    print("现在时间为: ", get_build_time())
