class Time:
    def __init__(self, hour=0, minute=0, second=0):
        # Just store the values without validation
        self.__hour = hour
        self.__minute = minute
        self.__second = second

    def display(self):
        # Display time in HH:MM:SS format
        print(f"{self.__hour:02d}:{self.__minute:02d}:{self.__second:02d}")

    def add_seconds(self, sec):
        # Simple addition using seconds and wrap around 24 hours
        total_seconds = self.__hour * 3600 + self.__minute * 60 + self.__second + sec
        total_seconds %= 24 * 3600
        self.__hour = total_seconds // 3600
        total_seconds %= 3600
        self.__minute = total_seconds // 60
        self.__second = total_seconds % 60


# Usage
t = Time(23, 59, 50)
t.display()        # 23:59:50
t.add_seconds(15)
t.display()        # 00:00:05
