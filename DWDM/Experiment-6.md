## Using the BASKETS1n dataset, select the data as given below.

a) Derive the field where home own is 'YES' and Age > 30, sort data by income in ascending order, and output only the item fields.

b) Find the mean value of salary with respect to age categories: Young, Middle, Senior.

### Solution: 6.a)

**Expected Output:**
![Expected Output](image-25.png)

**Output Dataset:**
![Output Dataset](image-26.png)

**Procedure:**
1. Specify the name of the file. Enter a filename or click the ellipsis button (...) to select a file. The file path is shown once selected, and its contents are displayed with delimiters in the panel below it.
2. Select `var.file` from sources, then navigate to `C:\Program Files (x86)\SPSS Clementine\11.1\Demos\BASKETS1n` to get the baskets file.
3. Go to Field Ops, search for Derive, and set the condition as shown in the figure.

    ![Step 3](image-27.png)

4. Connect Derive to Select with the condition shown in the figure.

    ![Step 4](image-28.png)

5. Connect Select to Sort for sorting Income in ascending order.

    ![Step 5](image-29.png)

6. Connect Sort to Filter to exclude all non-item fields.

    ![Step 6](image-30.png)

7. Select the output table and connect it with Filter.
8. Right-click on the output table and execute it.
9. Click on run; the output will be displayed.

### Solution: 6.b)

**Expected Output:**
![Expected Output](image-31.png)

**Output Dataset:**
![Output Dataset](image-32.png)

**Procedure:**
1. Specify the name of the file. Enter a filename or click the ellipsis button (...) to select a file. The file path is shown once selected, and its contents are displayed with delimiters in the panel below it.
2. Select `var.file` from sources, then navigate to `C:\Program Files (x86)\SPSS Clementine\11.1\Demos\BASKETS1n` to get the baskets file.
3. Go to Field Ops, search for Binning, and set the condition as shown in the figure.

    ![Step 3](image-33.png)

4. Connect Binning to Type to read data types and values as shown in the figure.

    ![Step 4](image-34.png)

5. Connect Type to Reclassify, classifying age binned in 1, 2, 3 to Young, Middle, Senior respectively.

    ![Step 5](image-35.png)

6. Connect Reclassify to Aggregate to get the income mean with respect to different age categories.

    ![Step 6](image-36.png)

7. Select the output table and connect it with Aggregate.
8. Right-click on the output table and execute it.
9. Click on run; the output will be displayed.