import time
import pandas as pd
import numpy as np

CITY_DATA = { 'chicago': 'chicago.csv',
              'new york city': 'new_york_city.csv',
              'washington': 'washington.csv' }

def get_filters():
    """
    Asks user to specify a city, month, and day to analyze.

    Returns:
        (str) city - name of the city to analyze
        (str) month - name of the month to filter by, or "all" to apply no month filter
        (str) day - name of the day of week to filter by, or "all" to apply no day filter
    """
    print('Hello! Let\'s explore some US bikeshare data!')
    # get user input for city (chicago, new york city, washington). HINT: Use a while loop to handle invalid inputs
    # ==================================================

    city = input("choose city you want to analyze (chicago, new york city, washington) : ").lower().strip()
    while city not in CITY_DATA.keys():
        city = input("enter a vaild value : ")
    #====================================================

    # get user input for month (all, january, february, ... , june)
    months_name = ['january', 'february', 'march', 'april', 'may', 'june' , 'all']
    month= input("\nwhich month (january, february, march, april, may, june , all): ").lower().strip()
    while month not in months_name:
        month = input("enter a vaild value : ")

    # get user input for day of week (all, monday, tuesday, ... sunday)
    days = ['monday', 'tuesday', 'wednesday', 'thursday','friday' ,'sunday' ,'saturday'  ,'all']
    day = input("which day : ").lower().strip()
    while day not in days:
        day = input("enter a vaild value : ")
    print('-'*40)
    return city, month,day

#=========================================================

def load_data(city, month,day):
    """
    Loads data for the specified city and filters by month and day if applicable.

    Args:
        (str) city - name of the city to analyze
        (str) month - name of the month to filter by, or "all" to apply no month filter
        (str) day - name of the day of week to filter by, or "all" to apply no day filter
    Returns:
        df - Pandas DataFrame containing city data filtered by month and day
    """
    print(city , " " , month  , " " , day)#يزال
    df = pd.read_csv(CITY_DATA[city])
    df["Start Time"] = pd.to_datetime(df['Start Time'])
    df["month"] = df['Start Time'].dt.month
    df["day_name"] = df['Start Time'].dt.day_name()
    df["hour"] = df['Start Time'].dt.hour

    if month != 'all':
        months = ['january', 'february', 'march', 'april', 'may', 'june']
        month = months.index(month)+1
        df = df[df['month'] == month]
    if day != 'all':
        df = df[df['day_name'] == day.title()]
    return df

def time_stats(df):
    """Displays statistics on the most frequent times of travel."""

    print('\nCalculating The Most Frequent Times of Travel...\n')
    start_time = time.time()

    # display the most common month
    print(f"the most common month is : {df['month'].mode()[0]}")

    # display the most common day of week
    print(f"the most common day of week is : {df['day_name'].mode()[0]}")

    # display the most common start hour
    print(f"the most common start hour is : {df['hour'].mode()[0]}")

    print("\nThis took %s seconds." % (time.time() - start_time))
    print('-'*40)

def station_stats(df):
    """Displays statistics on the most popular stations and trip."""

    print('\nCalculating The Most Popular Stations and Trip...\n')
    start_time = time.time()

    # display most commonly used start station
    
    print(f"the most common used start station is : {df['Start Station'].mode()[0]}")

    # display most commonly used end station
    print(f"the most common used end station is : {df['End Station'].mode()[0]}")


    # display most frequent combination of start station and end station trip
    df["route"] = df["Start Station"] + "," + df['End Station']
    print(f"the most common route is : {df['route'].mode()[0]}")

    print("\nThis took %s seconds." % (time.time() - start_time))
    print('-'*40)

def trip_duration_stats(df):
    """Displays statistics on the total and average trip duration."""

    print('\nCalculating Trip Duration...\n')
    start_time = time.time()

    # display total travel time
    print(f"total travel time = " , (df['Trip Duration'].sum()).round())

    # display mean travel time
    print(f"mean travel time = {(df['Trip Duration'].mean()).round()}")

    print("\nThis took %s seconds." % (time.time() - start_time))
    print('-'*40)

def user_stats(df , city):
    """Displays statistics on bikeshare users."""

    print('\nCalculating User Stats...\n')
    start_time = time.time()

    # Display counts of user types
    print(df["User Type"].value_counts().to_frame())

    # Display counts of gender
    if city != 'washington' :
        print(df["Gender"].value_counts().to_frame())

    # Display earliest, most recent, and most common year of birth
        print("the earliest year of breath is :" , int(df["Birth Year"].min()))
        print("the most recent year of breath is :" , int(df["Birth Year"].max()))
        print("the most common year of breath is :" , int(df["Birth Year"].mode()[0]))
    
    else :
        print("there is no data for this city for gender or breah year")

    print("\nThis took %s seconds." % (time.time() - start_time))
    print('-'*40)


def main():
    while True:
        city, month, day = get_filters()
        df = load_data(city, month, day)

        time_stats(df)
        station_stats(df)
        trip_duration_stats(df)
        user_stats(df , city)
        restart = input('\nWould you like to restart? Enter yes or no.\n')
        if restart.lower() != 'yes':
            break


main()