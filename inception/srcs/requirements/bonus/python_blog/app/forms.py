from flask_wtf import FlaskForm
from wtforms import StringField, SubmitField, PasswordField
from wtforms.validators import DataRequired, URL
from flask_ckeditor import CKEditorField



##WTForm
class CreatePostForm(FlaskForm):
    title = StringField("Τίτλος Blog", validators=[DataRequired()])
    subtitle = StringField("Υπότιτλος", validators=[DataRequired()])
    img_url = StringField(" Εικόνα Blog", validators=[DataRequired(), URL()])
    body = CKEditorField("Περιεχόμενο", validators=[DataRequired()])
    submit = SubmitField("Υποβολή Άρθρου")


class RegisterForm(FlaskForm):
    email = StringField("Email", validators=[DataRequired()])
    password = PasswordField("Κωδικός", validators=[DataRequired()])
    name = StringField("Όνομα", validators=[DataRequired()])
    submit = SubmitField("Εγγραφή!")


class LoginForm(FlaskForm):
    email = StringField("Email", validators=[DataRequired()])
    password = PasswordField("Κωδικός", validators=[DataRequired()])
    submit = SubmitField("Επαλήθευση")


class CommentForm(FlaskForm):
    comment_text = CKEditorField("Σχόλιο", validators=[DataRequired()])
    submit = SubmitField("Υποβολή Σχολίου")


