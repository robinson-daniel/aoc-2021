Usage:  
<sub>Download the input file.  


sonar_sweep.c:  
```
$ gcc sonar_sweep.c
$ chmod +x a.out
$ ./a.out input
```

sonar_sweep.py:  
<sub><sup><b>NOT WORKING</b></sup></sub>  
<sub>Tested with python3</sub>  
```
$ python sonar_sweep.py
```
</br>  

I was wondering why the output was off by one  
Going from a 3 digit integer to 4 was too hot to handle  
```
Output:
...
991  (increased)
count =  164
index =  202

994  (increased)
count =  165
index =  203

1001  (decreased) <- wtf
1023  (increased)
count =  166
index =  205

1027  (increased)
count =  167
index =  206
```

The pattern repeats when we increase digits then settles on the next iteration.  
```
8026  (increased)
count =  1547
index =  1999

9994  (increased)
count =  1548
index =  2000

10001  (decreased) <-
10002  (increased)
count =  1549
index =  2002

10006  (increased)
count =  1550
index =  2003

99999  (increased)
count =  1551
index =  2004

100001  (decreased) <-
999999  (increased)
count =  1552
index =  2006

1000001  (decreased) <-
9999999  (increased)
count =  1553
index =  2008

10000001  (decreased) <-
...
```

All other times it worked as intended.  
```
Output:
...
1189  (increased)
count =  197
index =  244

1188  (decreased)
1187  (decreased)
1192  (increased)
count =  198
index =  247

1190  (decreased)
1189  (decreased)
1184  (decreased)
1194  (increased)
count =  199
index =  251
...

8026  (increased)
count =  1547
index =  1999
There are  1547  measurements that are larger than the previous measurement
```

C version:  
```
Output:
...
8026 (increased)
count = 1548
index = 1999
There are 1548 measurements that are larger than the previous measurement <- correct answer
```