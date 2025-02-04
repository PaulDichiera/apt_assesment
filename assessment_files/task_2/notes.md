- 2D vectors

when constructing a 2d vector we are creating a vector of vectors, in this we have rows and columns the rows are one vector and the columns in each row are vectors

So in out constructor we already have the vector of vectors initialised as a member variable, we then take the assigned rows and columns.
for the rows they will dictate the number of times we iterate through our for loop, within the for loop we are creating a vector or a rowthat will be pushed onto our member variable
in this we declare that it is a vector using std::vector<Pixel>, we also declare the type we are containing in the vector, we can name the vector in this instance we call it myRow

we then pass in (the number of columns, and the valie in each index) in this case we pass in the Pixel() constructor as it will apply default values.

after we use this->img.push_back(myRow); we pass it onto the end of out member vector filling it wil rows of pixels.