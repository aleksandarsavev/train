#!/usr/bin/env python
from flask import Flask
from flask_restful import Resource, Api, reqparse

app = Flask(__name__)
api = Api(app)



MINERS = []

class Miners(Resource):
    def __init__(self):
        self.parser = reqparse.RequestParser()
        self.parser.add_argument('name')

    def get(self):
        return MINERS

    def post(self):
        args = self.parser.parse_args()
        print(args)
        return 'Hi'

@app.route('/')
def index():
    return 'Hello, World!'

api.add_resource(Miners, '/miners')

if __name__ == '__main__':
    app.run(debug=True)
