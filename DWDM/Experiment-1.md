1. **Using BASKETS1N Compare the GRI and Apriori with support 22% and confidence 90% usage (prepare a sample data set in a spreadsheet)**

    **Solution:**

    **Expected output:**
    ![Expected Output](image.png)

    **Input data set:** An Excel file is prepared as shown below:
    ![Input Data Set](image-1.png)
    ![Input Data Set](image-2.png)

    **Output dataset:**
    The below outputs show that there is no difference in rules generated from the Apriori and GRI (Generalized Rule Induction), but the order is changed. In Apriori, first low-level frequent item sets rules are generated and subsequently the next level frequent itemset rules. Whereas in GRI, the rules are generated on Items i.e. first largest rule then smallest rule size for one item, then the same for subsequent items.
    ![Output Data Set](image-3.png)

    **Procedure:** The following are the nodes used for this exercise with respective settings.
    ![Procedure Nodes](image-4.png)

    **Settings for Apriori:**
    ![Settings for Apriori](image-5.png)

    **Settings for GRI:**
    ![Settings for GRI](image-6.png)


