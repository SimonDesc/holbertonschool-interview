# Project: Log Parsing Script 📊🔍

## Table of Contents

- [Introduction](#introduction)
- [Practical Application](#practical-application)
- [Project Description](#project-description)
- [Script Details](#script-details)
- [Expected Output](#expected-output)
- [Conclusion](#conclusion)

## Introduction

Welcome to the Log Parsing Script project, a practical exercise designed to enhance your skills in data manipulation, regular expressions, and signal handling in programming. 🚀 This project challenges you to process web server logs in real-time, extracting and computing valuable metrics without the use of external libraries. It's a fantastic opportunity to work on a common backend task that simulates processing large datasets efficiently and effectively. 📈

## Practical Application

- **Real-Time Data Processing**: Learn to handle data streams in a real-time context, simulating the processing of live web server logs.
  
- **Signal Handling**: Understand and implement signal handling in scripts to manage external interruptions, such as keyboard interrupts.

## Project Description

Your mission is to create a script that reads standard input (stdin) line by line, parsing each log entry according to a specified format. The script will compute and display metrics based on the log data, including total file size and the count of HTTP status codes encountered.

## Script Details

- **Input Format**: Each line should follow the format: `<IP Address> - [<date>] "GET /projects/260 HTTP/1.1" <status code> <file size>`. Lines not matching this format should be ignored.
- **Metrics**:
  - **Total File Size**: After every 10 lines or upon receiving a keyboard interruption (`CTRL + C`), print the cumulative file size of all processed log entries.
  - **Status Code Counts**: Display the count of occurrences for each HTTP status code in ascending order. Only include status codes that appear in the input.

## Expected Output

- Implement your script to handle varied and unpredictable input, reflecting the nature of real-world web server logs.
- The script should remain robust and performant, processing large volumes of data without significant delays or errors.
- Ensure your script gracefully handles keyboard interruptions, printing the current metrics before terminating.

## Conclusion

This project not only sharpens your programming skills but also prepares you for tasks involving data processing and analysis in software development and IT operations. 🛠️💻 By tackling this challenge, you gain a deeper understanding of log management and the importance of efficient data processing techniques in maintaining and analyzing digital systems.
