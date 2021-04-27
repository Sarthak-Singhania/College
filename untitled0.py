import yfinance as yf
import pandas as pd
from time import sleep
while True:
    tatasteel=yf.Ticker('TATASTEEL.NS')
    df=pd.DataFrame(tatasteel.history('1d','1m'))
    df=df[['High','Low','Volume']][-7:]
    high=df[['High']].values
    low=df[['Low']].values
    flag=0
