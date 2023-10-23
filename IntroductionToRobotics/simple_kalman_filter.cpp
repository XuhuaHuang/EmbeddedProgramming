/**
 * @file simple_kalman_filter.cpp
 * @author Xuhua Huang
 * @brief
 * @version 0.1
 * @date 2023-10-13
 *
 * @copyright Copyright (c) 2023
 *
 */

#include <iostream>

/// @brief define the initial state and initial estimate of error
float initial_state    = 0;
float initial_estimate = 1;

/// @brief define process and measurement noise
float process_noise     = 0.1;
float measurement_noise = 0.5;

/// @brief Kalman filter variables
float state          = initial_state;
float estimate       = initial_state;
float error_estimate = initial_estimate;

/// @brief Kalman filter function
auto kalman_filter(const float measurement) -> void
{
    // Prediction
    float prediction       = state;
    float prediction_error = error_estimate + process_noise;

    // Update
    float kalman_gain = prediction_error / (prediction_error + measurement_noise);
    state             = prediction + kalman_gain * (measurement - prediction);
    error_estimate    = (1 - kalman_gain) * prediction_error;
    estimate          = state;

    return;
}

int main()
{
    // Simulated measurements
    float measurements[] = {1.2, 1.6, 2.0, 1.8, 2.2};

    for (int i = 0; i < sizeof(measurements) / sizeof(measurements[0]); i++)
    {
        float measurement = measurements[i];
        kalman_filter(measurement);

        std::cout << "Measurement: " << measurement << " Estimated State: " << estimate << "\n";
    }

    return 0;
}
