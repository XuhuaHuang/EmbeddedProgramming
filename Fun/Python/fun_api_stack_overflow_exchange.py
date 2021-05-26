# Topic: API usage example to website destination
# https://api.stackexchange.com//2.2/posts?order=desc&sort=activity&site=stackoverflow
# Stack Overflow API exchange, posts
# Author: Xuhua Huang
#
# Last updated: May  26, 2021
# Created on: May 26, 2021
#

import requests
import json


def main():
    print("Hello, world")

    '''
    retrieve response from stack overflow API website
    get data and sort by activity
    '''
    response = requests.get('https://api.stackexchange.com//2.2/posts?order=desc&sort=activity&site=stackoverflow')
    print(response)  # print json file size, expecting 200
    print(response.json()['items'])  # call json() method to print data in the output terminal

    # print all links to posts in the json document
    # add tab to format output
    for data in response.json()['items']:
        print("Type: " + data['post_type'] + "\t" + " Link: " + data['link'])


if __name__ == '__main__':
    main()
