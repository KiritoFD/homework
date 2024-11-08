pop0=3120324986
for year in range(1,6):
    pop=pop0+(int)(year*365*24*3600/7)-(int)(year*365*24*3600/13)+(int)(year*365*24*3600/45)-(int)(year*365*24*3600/79)
    print(pop)