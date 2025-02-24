# Stock Data Analysis and Forecasting with Transformer Model

This project demonstrates how to fetch stock data, preprocess it, normalize the dataset, and use a Transformer model for time-series forecasting. The data is fetched from GitHub, processed, and then trained using a custom Transformer-based neural network model built with TensorFlow/Keras.

## Project Workflow

### 1. Fetching Stock Data
The script fetches historical stock data from GitHub using the `pyfinancialdata` library. Data from 2010 to 2018 is fetched, concatenated into a single dataset, and saved as a CSV file.

### 2. Data Preprocessing
The fetched data is filtered for a specific time range (9:00 AM to 3:29 PM), and the stock prices ('open', 'high', 'low', 'close') are normalized using `MinMaxScaler` from `sklearn`. The normalized columns are added to the original dataset for further analysis.

### 3. Time Series Forecasting
- The `close_normalized` column is used to prepare the data for training. A look-back window of 60 time steps is used to create input sequences for the model.
- A custom Transformer model is implemented using `TensorFlow` and `Keras`, including Multi-Head Attention layers and Feed-Forward layers for forecasting.
- The model is trained on the historical data to predict the closing prices for the next 30 minutes.

### 4. Predictions
The model is evaluated, and predictions are made for the test set. The forecasted prices for the next 30 minutes are also generated using the trained model.

---

## Dependencies

To run this project, you need the following libraries:

- `pandas`: For data manipulation and processing
- `numpy`: For numerical operations
- `scikit-learn`: For data preprocessing (MinMax scaling)
- `tensorflow`: For building and training the Transformer model
- `pyfinancialdata`: For fetching historical stock data

You can install the required libraries using:

```bash
pip install pandas numpy scikit-learn tensorflow pyfinancialdata
```

## Usage

1. **Fetch Stock Data**  
   The script fetches the data for the SPXUSD instrument from 2010 to 2018 and concatenates it into a single CSV file.

   ```python
data_2010_2018.to_csv('/UMKC_Assignments/spxusd_2010_2018.csv')
   ```

2. **Preprocess Data**  
   The data is filtered for the 9:00 AM to 3:29 PM time range and normalized:

   ```python
   filtered_data = data_2010_2018.between_time('09:00', '15:29')
   ```

   The selected columns are normalized using the `MinMaxScaler`.

3. **Train the Transformer Model**  
   A custom Transformer model is defined and trained on the normalized closing price data:

   ```python
   model.fit(X_train, y_train, epochs=20, batch_size=32)
   ```

4. **Make Predictions**  
   The model predicts the closing prices for the next 30 minutes:

   ```python
   forecast = model.predict(last_data)
   ```

5. **Evaluate the Results**  
   Inverse transform the predictions to obtain actual predicted prices:

   ```python
   predictions = scaler.inverse_transform(predictions)
   ```

---

## Output Example

After training, the model predicts the following close prices [Example] for the next 30 minutes:

```bash
Forecasted close prices for the next 30 minutes:
[[601.25]
 [601.25]
 [601.25]
 ...
 [601.25]]
```

---

## Performance

The model trains over 20 epochs, with the loss decreasing progressively:

```bash
Epoch 1/20
Epoch 2/20
...
Epoch 20/20
```

---

## Future Improvements

1. **Hyperparameter Tuning:** Experiment with different model architectures, hyperparameters, and optimizers to improve performance.
2. **Add Positional Encoding:** Positional encoding can be added to the model for better sequence prediction.
3. **Additional Data:** Incorporate additional features such as volume, moving averages, or external market indicators to improve predictions.

---
