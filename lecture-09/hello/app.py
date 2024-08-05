from flask import Flask, render_template,request

app = Flask(__name__)

@app.route("/", methods = ["POST", "GET"])
def index():
    if request.method == "POST":
        name = request.form.get("name", "world")
        return render_template("greet.html", name=name)
    return render_template("index.html")
