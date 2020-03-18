####################################################################################################
################################## Various settings for multiplots #################################
####################################################################################################

# ~~~ TODO ~~~
# [ ] xtics for all plots at the bottom
 
# Variables nx and ny (number of columns and rows) have to be set in plot file before loading this file.
w = (rm-lm)/nx; h = (tm-bm)/ny # Width and height of subplots
 
set multiplot layout ny,nx # Set multiplot layout with ny rows and nx columns
 
# Create macros corresponding to each subplot. Usage: @Piyix will set the margins for the subplot. Additional settings can be appended to the macro string before evaluation or executed seperatly
subPltList="" # List containing subplot handles
 
do for [iy=1:ny] {
  do for [ix=1:nx] {
    if (((iy-1)*nx+ix) <= iMax) {
      eval(sprintf("P%i%i = subPltMrgns(tm-(iy-1)*h,tm-iy*h,lm+(ix-1)*w,lm+ix*w)",iy,ix))
      subPltList=subPltList.sprintf("P%i%i ",iy,ix)
    }                                   # |
  }                                     # |___________
}                                       #             |

# Unset xtics and label for upper rows, if there are more than one
if (ny > 1) {
   
  eval(word(subPltList,1).'='.word(subPltList,1).'.unsetXLabel.unsetXTics') # Unset xlabel and xtics if multiplot has multiple rows
  
  if (nx > 1) {
    eval(word(subPltList,iMax-nx+1).'='.word(subPltList,iMax-nx+1).'.setXTics')
  }
  else {
    eval(word(subPltList,iMax).'='.word(subPltList,iMax).'.setXTics')
  }
  # TODO Obsolete?
  # eval(sprintf("P%i1",ny).'='.sprintf("P%i1",ny).'.setXTics') # Set xtics for bottom subplot in each column
   
  # TODO Obsolete? Not reasonable for even number of columns
  #ix = iMax-(ny-1)*nx # Subplots in last row
  #eval(sprintf("P%i%i",ny,ceil(ix/2.0)).'='.sprintf("P%i%i",ny,ceil(ix/2.0)).'.setXLabel') # Set xlabel for central column subplot in last row
  #if ((iMax-(ny-1)*nx) > 2) { # Unset xlabel again after the previous subplot if there are further columns TODO Check condition
  #  eval(sprintf("P%i%i",ny,ceil(nx/2.0)+1).'='.sprintf("P%i%i",ny,ceil(nx/2.0)+1).'.setXLabel')
  #}
}

# Unset ytics and label for columns right from first one, if there are more than one
if (nx > 1) {
  do for [iy=1:ny] {
    eval(word(subPltList,(iy-1)*nx+1).'='.word(subPltList,(iy-1)*nx+1).'.setYTics') # Unset ylabel and xtics if multiplot has multiple columns
    if (iMax-(iy-1)*nx > 1) {
      eval(word(subPltList,(iy-1)*nx+2).'='.word(subPltList,(iy-1)*nx+2).'.unsetYTics') # Unset ylabel and xtics if multiplot has multiple columns
    }
  }
}

#eval(word(subPltList,iMax).'='.word(subPltList,iMax).'.setXLabel.setYLabel')
