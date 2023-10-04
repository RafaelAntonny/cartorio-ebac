create table usuarios
(
  cpf integer,
  nome varchar(50),
  sobrenome varchar(50),
  cargo varchar(50),
  curso_id integer
);

create table cursos
(
  id integer,
  nome_curso varchar(100),
  professor varchar(50),
  categoria varchar(50)
);

insert into usuarios (cpf, nome, sobrenome, cargo, curso_id)
values('123', 'Pedro', 'Brocaldi', 'professor', '2');

insert into usuarios (cpf, nome, sobrenome, cargo, curso_id)
values('1234', 'Galileo', 'Galilei', 'professor', '1');

insert into usuarios (cpf, nome, sobrenome, cargo, curso_id)
values('12345', 'John', 'Doe', 'aluno', '2');

insert into usuarios (cpf, nome, sobrenome, cargo, curso_id)
values('123456', 'Jane', 'Doe', 'aluno', '1');

insert into cursos (id, nome_curso, professor, categoria)
values('1', 'Curso de Astrofisica' , 'Galileo Galilei', 'Astronomia');

insert into cursos (id, nome_curso, professor, categoria)
values('2', 'TI Zero ao Pro' , 'Pedro Brocaldi', 'Programação');

update usuarios
set curso_id = '2'
where cpf = '123456';

select * from usuarios
where cpf = '123456';