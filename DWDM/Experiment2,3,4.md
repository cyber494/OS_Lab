Experiments: 2,3,4
2.	Determine the Drugs importance with respect to Age, Cholesterol and BP using C 5.0.
3. Predict the accuracy of the test data set using Neural Net model using a Case Study of Botanical data set.
4.	Compare the C 5.0 and Neural Net using the sample data.
SOLUTION:
Expected output:
![alt text](image-7.png)




Input data set:
![alt text](image-8.png)
Output dataset:

Output of Neural Net Model
![alt text](image-9.png)



Output of C5.0 Model 

![alt text](image-10.png)
Output of C5.0 Model viewer which is shown in tree format

![alt text](image-11.png)

Comparision: Attribute Importance is as follows
Neural net Model	: BP- 0.2928, Age- 0.1070, Cholestrol- 0.1023
C 5.0			: 2 Level Decision Tree is prepared with BP as root attribute (level 1) with Age and Cholesterol Attributes at level 2
** As a result, Neural Net and C 5.0 Models are giving the same information.

Procedure:  The following are the nodes used for this exercise with respective settings.

![alt text](image-12.png)




Settings for C5.0 Model

![alt text](image-13.png)



Settings for Neural Net Model

![alt text](image-14.png)