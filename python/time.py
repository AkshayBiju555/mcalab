'''class Time:
    def __init__(self, hour=0, minute=0, second=0):
        # Validate hour
        if 0 <= hour < 24:
            self.__hour = hour
        else:
            self.__hour = 0

        # Validate minute
        if 0 <= minute < 60:
            self.__minute = minute
        else:
            self.__minute = 0

        # Validate second
        if 0 <= second < 60:
            self.__second = second
        else:
            self.__second = 0

    def display_time(self):
        print(f"{self.__hour:02d}:{self.__minute:02d}:{self.__second:02d}")

    def add_seconds(self, sec):
        total = self.__hour * 3600 + self.__minute * 60 + self.__second + sec
        total %= 24 * 3600  # wrap around after 24 hours

        self.__hour = total // 3600
        total %= 3600
        self.__minute = total // 60
        self.__second = total % 60


# Usage example:
t = Time(23, 59, 50)
t.display_time()      # 23:59:50

t.add_seconds(15)
t.display_time()      # 00:00:05 (after rollover)
'''
class Time:
    def __init__(self,hour,minute,second):
        self.__hour=hour
        self.__minute=minute
        self.__second=second
    def __add__(self,other):
        s=self.__second+other.__second
        m=self.__minute+other.__minute
        h=(self.__hour+other.__hour)%24
        if s>=60:
            s%=60
            m+=1
        if m>=60:
            m%=60
            h+=1
        
        return Time(h,m,s)
    
    def __str__(self):
        return f"{self.__hour:02d}:{self.__minute:02d}:{self.__second:02d}"

t1=Time(12,42,37)
t2=Time(12,22,59)
t3=t1+t2
print(t3)   
