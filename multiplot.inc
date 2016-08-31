# Various settings for multiplots
# Variables nx and ny (number of columns and rows) have to be set in plot file before loading this file.
w = (rm-lm)/nx; h = (tm-bm)/ny # Width and height of subplots
 
set multiplot layout ny,nx # Set multiplot layout with ny rows and nx columns
 
# Create macros corresponding to each subplot. Usage: @Piyix will set the margins for the subplot. Additional settings can be appended to the macro string before evaluation or executed seperatly
subPltList="" # List containing subplot handles
do for [iy=1:ny] {
  do for [ix=1:nx] {
    eval(sprintf("P%i%i = subPltMrgns(tm-(iy-1)*h,tm-iy*h,lm+(ix-1)*w,lm+ix*w)",iy,ix))
    subPltList=subPltList.sprintf("P%i%i ",iy,ix)
  }
}
subPltList=subPltList[:strlen(subPltList)-1] # Remove trailing space
