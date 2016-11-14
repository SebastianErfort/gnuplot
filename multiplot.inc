####################################################################################################
################################## Various settings for multiplots #################################
####################################################################################################
 
# Variables nx and ny (number of columns and rows) have to be set in plot file before loading this file.
w = (rm-lm)/nx; h = (tm-bm)/ny # Width and height of subplots
 
set multiplot layout ny,nx # Set multiplot layout with ny rows and nx columns
 
# ~~~ Create macros corresponding to each subplot. Usage: @Piyix will set the margins for the subplot. Additional settings can be appended to the macro string before evaluation or executed seperatly
 
# Set up the list
subPltList="" # List containing subplot handles
do for [iy=1:ny] {
  do for [ix=1:nx] {
    if (((iy-1)*nx+ix) <= iMax) {
      eval(sprintf("P%i%i = subPltMrgns(tm-(iy-1)*h,tm-iy*h,lm+(ix-1)*w,lm+ix*w)",iy,ix))
      subPltList=subPltList.sprintf("P%i%i ",iy,ix)
    } #                                   |
  }   #                                   |___________
}     #                                               |
subPltList=subPltList[:strlen(subPltList)-1] # Remove trailing space


# ~~~ LABELS and TICS

eval(setXLabel)
# Unset xtics for upper rows, if there are more than one
if (ny > 1) {
  eval(word(subPltList,1).'='.word(subPltList,1).'.unsetXTics') # Unset xlabel and xtics if multiplot has multiple rows
  eval(sprintf("P%i1",ny).'='.sprintf("P%i1",ny).'.setXTics') # Set xtics for last row
}

eval(setYLabel)
# Unset ytics for columns right from first one, if there are more than one
# TODO check and correct
if (nx > 1) {
  do for [iy=1:ny] {
    eval(word(subPltList,(iy-1)*nx+1).'='.word(subPltList,(iy-1)*nx+1).'.setYTics') # Unset ylabel and xtics if multiplot has multiple columns
    eval(sprintf('P%i1=P%i1',iy,iy).'.setYTics') # Set ytics for first column
    eval(sprintf('P%i2=P%i2',iy,iy).'.unsetYTics') # Unset ytics for columns right from first one
  }
}
