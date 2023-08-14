# Make a heat map plot of specific columns in a data file

if (exist('l')) {eval('specVal=l')}
else {print 'Specify l!'; exit
}
cols=""
do for [l=+1:K*L:L] {cols=cols.sprintf('$%d,',l)}
cols=cols[:strlen(cols)-1] # Remove trailing comma
system(sprintf("awk -F ' ' '{print %s}' %s > tmp.dat",cols,dataDir.dataFile))
 
pltCmd='splot "tmp.dat" matrix w pm3d not;' # Plot command, will be executed in plot*.gpls # TODO adapt for column plot 
 
system('rm tmp.dat') # Clean up
