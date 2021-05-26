from flask import Flask, jsonify, request
from flask_sqlalchemy import SQLAlchemy

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:///data.db'
db = SQLAlchemy(app)


class Drink(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    name = db.Column(db.String(80), unique=True, nullable=False)
    description = db.Column(db.String(120))

    def __repr__(self):
        return "{} - {}".format(self.name, self.description)


@app.route('/')
def index():
    return "Greetings"


@app.route('/drinks')
def get_drinks():
    drinks = Drink.query.all()  # retrieve all drinks in the database
    output = []  # create an empty list to serve as a place holder for JSON object
    for drink in drinks:
        drink_data = {'name': drink.name, 'description': drink.description}
        output.append(drink_data)
    return {"drinks": output}


@app.route('/drinks/<id>')
def get_drink(id: int):
    drink = Drink.query.get_or_404(id)
    return jsonify({'name': drink.name, 'description': drink.description})


@app.route('/drinks', methods=['POST'])
def add_drink():
    drink = Drink(name=request.json['name'], description=request.json['description'])
    db.session.add(drink)
    db.session.commit()
    return {'id': drink.id}  # return new id for posted drink


@app.route('/drinks/<id>', method=['DELETE'])
def delete_drink():
    drink = Drink.quey.get(id)
    if drink is None:
        return {'Error': 'Drink not found to delete'}
    else:
        db.session.delete(drink)
        db.session.commit()
        return {'Confirmation': 'Successfully deleted drink'}
