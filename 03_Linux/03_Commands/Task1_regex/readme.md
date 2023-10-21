for emai.txt: 
```bash
grep -E -o '\b[A-Za-z0-9._%+-]+@[A-Za-z0-9.-]+\.[A-Za-z]{2,4}\b' email.txt
```

for phone.txt: 
```bash
grep -E -o '\b[0-9]{3}-[0-9]{3}-[0-9]{3}\b' phone.txt
grep -E -o '\b[0-9]{3}-[0-9]{3}-[0-9]{3}\b' phone.txt
```