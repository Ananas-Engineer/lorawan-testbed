var createError = require('http-errors');
var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');
var bodyParser = require('body-parser');
const session = require('express-session')



const indexRouter = require('./routes/index.route');
const dashboardRouter = require('./routes/dashboard.route');
const loginRouter = require('./routes/login.route');
const registerRouter = require('./routes/register.route');
const userRouter = require('./routes/user.route');
const deviceRouter = require('./routes/device.route');
const settingRouter = require('./routes/setting.route');
const logoutRouter = require('./routes/logout.route');

// var usersRouter = require('./routes/users');
// var diaryRouter = require('./routes/diary.route');

var app = express();

// view engine setup
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'ejs');

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use(session({
	secret: 'secret',
	resave: true,
	saveUninitialized: true
}));
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());

app.use('/', indexRouter);
app.use('/dashboard', dashboardRouter);
app.use('/login', loginRouter);
app.use('/register', registerRouter);
app.use('/user', userRouter);
app.use('/device', deviceRouter);
app.use('/setting', settingRouter);
app.use('/logout', logoutRouter);

// app.use('/', indexRouter);
// app.use('/users', usersRouter);
// app.use('/diary/', diaryRouter);

// catch 404 and forward to error handler
app.use(function(req, res, next) {
  next(createError(404));
});

// error handler
app.use(function(err, req, res, next) {
  // set locals, only providing error in development
  res.locals.message = err.message;
  res.locals.error = req.app.get('env') === 'development' ? err : {};

  // render the error page
  res.status(err.status || 500);
  res.render('error');
});

module.exports = app;
